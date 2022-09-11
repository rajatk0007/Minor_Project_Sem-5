#include<iostream>
#include "naive_tsp_final_combine.cpp"
#include "dynamic_programming_final_combine.cpp"
#include "cities.h"
#include "tsp_matrix_generate_combine.cpp"
#include "Branch_and_bound_TSP_combine.cpp"
#include "genetic_algorithm_new.cpp"
using namespace std;


int main()
{
    int choice;
    int cities;
    cout<<"\nEnter the number of cities : ";
    cin>>cities;
    int solution_set_size;
    int total_gen;
    main_generator(cities);

    while(1){
        cout<<"\n\n1. Naive Algorithm"<<endl;
        cout<<"2. Dynamic Algorithm"<<endl;
        cout<<"3. Branch and Bound Algorithm"<<endl;
        cout<<"4. Genetic Algorithm"<<endl;
        cout<<"5. Use all Algorithms"<<endl;
        cout<<"6. Change number of cities"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"\n-----choice is Naive-----\n";
                main_naive();
                cout<<endl;
                continue;

            case 2:
            cout<<"\n-----choice is dynamic-----\n";
                main_dynamic();
                cout<<endl;
                continue;

            case 3:
                cout<<"\n-----choice is branch and bound-----\n";
                main_branchBound(cities);
                cout<<endl;
                continue;

            case 4:
                cout<<"\n-----choice is Genetic-----\n";
                cout<<"Enter solution set size\n";
                cin>>solution_set_size;
                cout<<"Enter total generations\n";
                cin>>total_gen;
                main_genetic(cities,solution_set_size,total_gen);
                cout<<endl;
                continue;

            case 5:
                cout<<"\n-----choice is all algorithms-----\n";
                cout<<"Enter solution set size for genetic\n";
                cin>>solution_set_size;
                cout<<"Enter total generations for genetic\n";
                cin>>total_gen;
                main_naive();
                cout<<endl;
                main_dynamic();
                cout<<endl;
                main_branchBound(cities);
                cout<<endl;
                main_genetic(cities,solution_set_size,total_gen);
                cout<<endl;
                continue;

            case 6:
                cout<<"\nEnter new number of cities: ";
                cin>>cities;
                main_generator(cities);
                continue;
                

            case 7:
                cout<<"\nExiting....\n"<<endl;
                exit(0);
                
                
            default:
                cout<<"\n-----Wrong choice!!!-----"<<endl;
                continue;

        }
    }
    return 0;
}
