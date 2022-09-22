#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include<stdio.h>
#include <string>
#include<sstream>
// #define INT_MAX 99999

using namespace std;
using namespace std::chrono;
using namespace std;

int min_path_calc(int a,int b){
	return (a<b)?a:b;
}

int Travlling_Salesman_Problem(vector<vector<int>> graph, int start)
{
	int cities = graph.size();
	
	//stores the all the cities except starting point 
    int *vert_cities = new int[cities-1];
    
    for(int i=0,j=0;i<cities;i++){
    	if(i!=start){
    		vert_cities[j] = i;
    		j++;
    	}
    }
    
    //stores the min cost possible to create a hamiltonian cycle throughout the given nodes
    int min_cost = INT_MAX;
    
    // int min_cost_path[cities+1] = {0};
    int *min_cost_path = new int[cities+1];
    min_cost_path[0] = start;
    
    //var to keep track whether all possible permutations are tested 
    bool flag = true;
    
    while(flag){
    	int curr_path_cost = 0;
    	
    	//keeps track of last city reached inside next loop
    	int j=0,end_city = start;
    	
    	for(int i=0;i<cities-1;i++){
    		int j = vert_cities[i];
    		curr_path_cost += graph[end_city][j];
    		end_city = j;
    	}
    	
    	//Adding the distance to be covered while coming back from last city -> starting city 
    	curr_path_cost += graph[end_city][j];
    	
    	// min_cost = min_path_calc(curr_path_cost,min_cost);
    	
    	if(curr_path_cost<min_cost){
    		min_cost = curr_path_cost;
    		copy(vert_cities,vert_cities + (cities-1),min_cost_path+1);
    	}
    
    	//returns true and alters the array/list to next higher permutation in terms of Lexicographic order
    	//otherwise returns false -> this will terminate the loop checking all permutations
    	flag = next_permutation(vert_cities,vert_cities + (cities-1));
    }
    
    // cout<<"Minimum cost path: ";
    // for(int i=0;i<cities;i++){
    // 	cout<<min_cost_path[i]<<" -> ";
    // }
    // cout<<min_cost_path[cities]<<endl;
    
    delete [] vert_cities;
    delete [] min_cost_path;
    
    return min_cost;
}

void main_naive()
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
    
	int start_point = 0;
    auto start = high_resolution_clock::now();
	int res = Travlling_Salesman_Problem(graph,start_point);
	// cout<<"Cost of shortest possible path: "<<res<<endl;
	auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"---------Naive programming----------"<<endl;
	cout<<"\tCost\t|\tTime"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"\t"<<res<<"\t\t"<<duration.count()<<" ms"<<endl;

    // cout<<"Time required by the algorithm: "<<duration.count()<<" microseconds";
	// return 0;
}
