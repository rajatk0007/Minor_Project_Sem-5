#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include<stdio.h>
#include<bits/stdc++.h>
#include <string>
#include<sstream>
#define INT_MAX_ 99999

using namespace std;
using namespace std::chrono;


int tspSolver(const vector<vector<int>>& graph, int current, int visited,vector<vector<int>>& mem)
{
    //if we have visited all nodes and we have to 
    //return back to the starting node
    if(visited == ((1 << graph.size()) - 1))
        return graph[current][0];

    //we use the previously computed value if mem entry is not -1
    if(mem[visited][current]!=-1){
        return mem[visited][current];
    }

    int distance = INT_MAX_;

    for(int i = 0; i < graph.size(); i++)
    {
        if((visited & (1<<i))==0){
            int dist = graph[current][i] + tspSolver(graph, i, visited | (1 << i),mem);
            distance = min(distance,dist);
        }

    }
    return mem[visited][current] = distance;
}


void main_dynamic()
{
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
    
    int n = graph.size();
    int default_value = -1;
    
    vector<int> v(n, default_value);

    //a memoization table for storing the values in the dp approach
    vector<vector<int> > mem((1<<n), v);
    
    auto start = high_resolution_clock::now();
    int res = tspSolver(graph, 0, 1,mem);
    // cout << "Minimum path distance: " << tspSolver(graph, 0, 1,mem) << endl;
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<"---------Dynamic programming------"<<endl;
	cout<<"\tCost\t|\tTime"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"\t"<<res<<"\t\t"<<duration.count()<<" ms"<<endl;

    // cout<<"Time required by the algorithm: "<<duration.count()<<" microseconds";

    // return 0;
}
