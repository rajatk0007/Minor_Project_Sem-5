#include<bits/stdc++.h>

using namespace std;
 
// #define N 3
int N;
#define Infinity INT_MAX
 
//State Space Tree nodes
struct Node
{
    vector<pair<int, int>> path;
 
    vector<vector<int>> reduce_mat;
 
    //stores the lower bound
    int cost;
  
    int cur_vert;
 
    //keeps track of total number of cities visited so far
    int level;
};

Node* createNode(vector<vector<int>> &graph, vector<pair<int, int>> &path, int level, int i, int j)
{
    Node* node = new Node;
 
    node->path = path;
    if (level != 0)
    {
        node->path.push_back(make_pair(i, j));
    }
 
    copy(graph.begin(), graph.end(), back_inserter(node->reduce_mat));
 
    for (int k=0; level!=0 && k<N; k++)
    {
        node->reduce_mat[i][k] = Infinity;
        node->reduce_mat[k][j] = Infinity;
    }
  
    node->reduce_mat[j][0] = Infinity;
 
    //number of cities visited so far and the current city
    node->level = level;
    node->cur_vert = j;
 
    return node;
}
 
 
//Function to get the lower bound on the path beginning at the current min node
int calc_PathCost(vector<vector<int>> &reduce_mat)
{
    int cost = 0;
 
    int row[N], col[N];
    // Row Reduction
    fill_n(row,N,Infinity);
    fill_n(col,N,Infinity);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reduce_mat[i][j] < row[i]) {
                row[i] = reduce_mat[i][j];
            }
        }
    }
 
    //reduce the min value from each row
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reduce_mat[i][j] != Infinity && row[i] != Infinity) {
                reduce_mat[i][j] -= row[i];
            }
        }
    }
    
    // Column Reduction
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reduce_mat[i][j] < col[j]) {
                col[j] = reduce_mat[i][j];
            }
        }
    }
 
    //reduce the min value from each column
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (reduce_mat[i][j] != Infinity && col[j] != Infinity) {
                reduce_mat[i][j] -= col[j];
            }
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        if(row[i] != INT_MAX)
        	cost = cost + row[i];
        
        if(col[i] != INT_MAX)
        	cost = cost + col[i];
        	
        else
        	cost = cost + 0;
    }
 
    return cost;
}

 
//Comparison object
struct comparatorCostNode
{
    bool operator()(Node* x, Node* y) 
    {
        return x->cost > y->cost;
    }
};

int TSP_branch_and_bound(vector< vector<int> > graph)
{
    priority_queue<Node*, vector<Node*>, comparatorCostNode> min_heap ;
 
    vector<pair<int, int>> v; //stores the path
 
    //It starts from the first city, i.e. node 0
    Node* root = createNode(graph, v, 0, -1, 0);
 
    //lower bound for the path starting at node 0
    root->cost = calc_PathCost(root->reduce_mat);
 
    //Adding the root to the list of live nodes
    min_heap.push(root);
    
    // Node *temp2;
    
    //Finding a live node with the least cost
    while (!min_heap.empty())
    {
        //node with least estimated cost
        Node* min = min_heap.top();
        // temp2 = min;
 
        min_heap.pop();
 
        //current city number
        int i = min->cur_vert;
 
        //if all cities are visited
        if (min->level == N - 1)
        {
            min->path.push_back(make_pair(i, 0));
            
            return min->cost;
        }
 
        for (int j = 0; j < N; j++)
        {
            if (min->reduce_mat[i][j] != Infinity)
            {
                Node* child = createNode(min->reduce_mat, min->path, min->level + 1,i,j);
                child->cost = min->cost + min->reduce_mat[i][j] + calc_PathCost(child->reduce_mat);
                min_heap.push(child);
            }
        }
 
        delete min;
    }
    return 0;
}

void main_branchBound(int cities)
{
    N = cities;
	vector<vector<int>> graph;
    string myText;
    ifstream fp("nodes.txt");
    string temp;  
    char delimiter;
    int temp1;
    while (getline(fp, temp)) 
    {
        istringstream iss(temp);
        vector<int> temp_vector;
        while (iss >> temp1) {  
                temp_vector.push_back(temp1);
                iss >> delimiter; 
                }
            graph.push_back(temp_vector);  
    }

    
    auto start = high_resolution_clock::now();
    int res = TSP_branch_and_bound(graph);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    // cout <<"\nCost of shortest possible path : "<< res;
    cout<<"---------BRANCH AND BOUND--------"<<endl;
	cout<<"\tCost\t|\tTime"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"\t"<<res<<"\t\t"<<duration.count()<<" ms"<<endl;
    
    //Printing the path
    // cout<<"The path followed : "<<temp->path[0].first + 1<<" -> ";
    // for (int i = 0; i < temp->path.size()-1; i++) {
    //     cout<<temp->path[i].second + 1<<" -> ";
    // }
    // cout<<temp->path[temp->path.size()-1].second + 1<<endl;
 
    // return 0;
}