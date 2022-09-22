#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<bits/stdc++.h>
#include"cities.h"
#define INF -9999
#define INF_MAX 99999
// #define N 5
int cities;

using namespace std;

vector<vector<int>> generate_file(int n){
srand((unsigned) time(0));
vector<vector<int>> graph;
int random_number;
    for (int i=0; i<n; i++) {
        vector<int> temp_vector;
    for (int j = 0; j < n; j++) {
        if(i==j)
        temp_vector.push_back(0);
        else if(j<i){
        random_number = rand()%100+1;
        temp_vector.push_back(random_number);
        }
        else
        temp_vector.push_back(INF);
        }
        graph.push_back(temp_vector);
    }
    
   int** temp;
   temp = new int*[n];
   for(unsigned i=0; (i < n); i++)
   { 
      temp[i] = new int[n];
      for(unsigned j=0; (j < n); j++)
      {
          temp[i][j] = graph[i][j];
      } 
   }
   for(int i=0;i<n;i++)
   {
   for(int j=0;j<n;j++){
       if(temp[i][j]==INF)
       temp[i][j]=temp[j][i];
    }
 }
    vector<vector<int>> graph1;
    for (int i = 0; i <n; i++)
   {    vector<int> temp_vector1;
      for (int j = 0; j <n; j++)
      {
         temp_vector1.push_back(temp[i][j]);
      }
      graph1.push_back(temp_vector1);
   }
  /* vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for (row = graph.begin(); row != graph.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout<<*col<<" ";
        }
        cout<<endl;
    }*/

    return graph1;
}

void main_generator(int cities)
{
    ofstream graph_file("nodes.txt");
    vector<vector<int>> graph;
    
    graph = generate_file(cities);
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for (row = graph.begin(); row != graph.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            graph_file<<*col<<",";
        }
        graph_file<<"\n";
    }
    
}
