//solving tsp using genetic algorithm
#include<iostream>
#include<math.h>
#include<vector>
#include<bits/stdc++.h>
#include<chrono>
#include<string>
#include<fstream>
#include<sstream>
//#define SOLUTION_SET_SIZE 100
// #define CITIES 50
int CITIES;
int SOLUTION_SET_SIZE;
int TOT_GEN;
using namespace std;
using namespace std::chrono;


struct solution {
    vector<int> path;
    int fitness;
};



bool occurred(vector<int> path, int occurence)
{
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == occurence)
            return true;
    }
    return false;
}

vector<int> make_path()
{
    vector<int> path;
    path.push_back(0);
    while (true) {
        if (path.size() == CITIES) {
            path.push_back(path[0]);
            break;
        }
        int range = CITIES-1;
        int temp = 1+ (rand() % range);
        if (!occurred(path,temp))
            path.push_back(temp);
    }
    return path;
}
 int calc_fitness(vector<int> path,vector<vector<int>> map)
{
    int f = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        f += map[path[i]][path[i + 1]];
    }
    return f;
}

int order(vector<struct solution> solution_set)
{
    int min = solution_set[0].fitness;
    for(int i=0;i<solution_set.size();i++){
        if(solution_set[i].fitness<min)
        min = solution_set[i].fitness;
    }
    return min;
}

vector<int> mutation(vector<int> path)
{
    while (true) {
        int range = CITIES-1;
        int pos = 1 + (rand() % range);
        int pos1 = 1 + rand() % range;
        if (pos1 != pos) {
            int temp = path[pos];
            path[pos] = path[pos1];
            path[pos1] = temp;
            break;
        }
    }
    return path;
}

bool check_fitness(struct solution s1,
              struct solution s2)
{
    return s1.fitness < s2.fitness;
}
int solve_TSP(vector<vector<int>> map,int SOLUTION_SET_SIZE,int TOT_GEN)
{
    vector<int> minimum_set;
    // Generation Number
    int gen_count = 1;
    // Number of Gene Iterations
    int tot_gen = TOT_GEN;
 
    vector<struct solution> solution_set;
    
    struct solution temp;
 
    // Populating the GNOME pool.
    for (int i = 0; i < SOLUTION_SET_SIZE; i++) {
        temp.path = make_path();
        temp.fitness = calc_fitness(temp.path,map);
        solution_set.push_back(temp);
    }
 
    // cout << "\nInitial population: " << endl<< "PATH       COST/TOTAL DIST\n";
    // for (int i = 0; i < SOLUTION_SET_SIZE; i++)
    //     cout<<solution_set[i].path<< "   "<< solution_set[i].fitness << endl;
    
    // cout << "\n";
 
 
    // Iteration to perform
    // population crossing and gene mutation.
    // int k=0;
    while (gen_count <= tot_gen) {
        // cout<<k++<<endl;
        sort(solution_set.begin(), solution_set.end(), check_fitness);
        vector<struct solution>::iterator x;
        // for(x = solution_set.begin();x<solution_set.end();x++){
        //     struct solution y = *x;
        //     cout<<y.fitness<<" ";
        // }
        // cout<<endl;
        // solution_set.resize(10);
        vector<struct solution> new_solution_set;
        for (int i = 0; i < SOLUTION_SET_SIZE; i++) {
            struct solution s1 = solution_set[i];
            for(int i=0;i<s1.path.size();i++){
                // cout<<s1.path[i]<<" ";
            }
            // cout<<endl;
            while (true) {
                // cout<<"mutation"<<endl;
                vector<int> new_p(CITIES+1); 
                new_p = mutation(s1.path);
                struct solution new_path;
                vector<int> temp1;
                temp1.assign(CITIES+1,0);
                new_path.path = temp1;
                new_path.path = new_p;
                for(int i=0;i<new_path.path.size();i++){
                    // cout<<new_path.path[i]<<" ";
                }
                // cout<<endl;
                new_path.fitness = calc_fitness(new_path.path,map);
                for(int i=0;i<new_path.path.size();i++){
                    // cout<<new_path.path[i]<<" ";
                    }
                // cout<<endl;
                if (new_path.fitness <= solution_set[i].fitness) {
                    new_solution_set.push_back(new_path);
                    
                    break;
                }
                else {
 
                    // Accepting the rejected children at
                    // a possible probability above threshold.
                    break;
                }
            }
        }

        // for(int i=0;i<CITIES;i++){
        //                 for(int j=0;j<new_solution_set[i].path.size();j++){
        //                     cout<<new_solution_set[i].path[j]<<" ";
        //                 }
        //                 cout<<endl;
        //             }
 
        // solution_set = new_solution_set;

        // for(int i=0;i<SOLUTION_SET_SIZE;i++){
        //     for(int j=0;j<solution_set[i].path.size();j++){
        //         cout<<solution_set[i].path[j]<<" ";
        //     }
        //     // cout<<endl;
        // }
        int minimum = order(solution_set);
        minimum_set.push_back(minimum);
        // cout<<"min_set"<<endl;
        for(int i=0;i<minimum_set.size();i++){
            // cout<<minimum_set[i]<<" ";
        }
        // cout<<endl;
        gen_count++;
    }
    
    vector<int>::iterator i;
    for (i = minimum_set.begin(); i != minimum_set.end(); i++) 
    {
        // cout<<*i;
    }
    int res = *min_element(minimum_set.begin(), minimum_set.end());
    // cout<<res;
    return res;
}

int main_genetic(int n,  int SOLUTION_SET_SIZE,int TOT_GEN){
    CITIES = n;
    // int map[CITIES][CITIES];
    vector<vector<int>> map(n);
    vector<vector<int>> graph;
    string myText;
    ifstream fp("nodes.txt");
    string temp;  
    char delimiter;
    int temp1;
    while (getline(fp, temp)) {
        istringstream iss(temp);
        vector<int> temp_vector;
        while (iss >> temp1) {  
            temp_vector.push_back(temp1);
            iss >> delimiter; 
            }
             graph.push_back(temp_vector);  
    }
//    for(unsigned i=0; (i < CITIES); i++)
//    { 
//       for(unsigned j=0; (j < CITIES); j++)
//       {
//           map[i][j] = graph[i][j];
//       } 
//    }

    auto start = high_resolution_clock::now();
    int res = solve_TSP(graph,SOLUTION_SET_SIZE,TOT_GEN);
    // cout<<res<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout<<"--------GENETIC ALGORITHM-----------"<<endl;
	cout<<"\tCost\t|\tTime"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"\t"<<res<<"\t\t"<<duration.count()<<" ms"<<endl;
    return 0;
}
