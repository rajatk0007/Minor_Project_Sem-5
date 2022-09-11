## Comparison of different algorithms to solve the TSP algorithm

This is a research project for the determining the best algorithm to solve the famous Travelling Salesman Problem under different dependable parameters like the number of cities and the cost between them.

### ABSTRACT

The Travelling Salesman Problem (TSP) is an algorithm-based problem which asks us the question “given a list of nodes and the distance between each pair of nodes, what is the shortest route that can be taken to cover all the nodes exactly once and return back to the starting node.”. This is a cost optimization problem, which can be solved by finding an optimal path. There have been multiple solutions for this in the past. The aim of this project is to compare various algorithms from different domains to the find the algorithm which can be implemented with the best time complexity, space complexity, and optimality of solution. The algorithms that would be tested in this project are- genetic algorithm (ML), branch and bound method, dynamic programming, and a naïve approach.


### INTRODUCTION

The Travelling Salesman Problem (TSP) is a NP-hard problem. The problem of TSP is to find the shortest path that covers all nodes in a graph returning to the starting point. The graph can represent real world scenarios, for example a map where the nodes are cities, and the edges are paths between them. This problem has various applications in the real world, which creates a need for efficient solutions. This project aims at comparing the efficiency of few such established solutions based on time complexity, space complexity and optimality of solution (the lowest distance). The algorithms under discussion in this project are: 
1.	Genetic Algorithm
2.	Branch and Bound Method
3.	Dynamic Programming
4.	Naïve Approach

Genetic Algorithm: Genetic algorithms (GAs) are a part of evolutionary algorithms which are generally used in optimization problems where either a high-cost value or a low cost one (based on the problem criteria) is required. These algorithms are classified as adaptive search algorithms which makes them quite flexible to different situations where optimal solutions need to be found. These solutions are also heuristic (can be executed within a given timeframe). Genetic algorithms consist of many steps:

1.	Selection - selecting the parent chromosomes that will take part in mating
2.	Crossover - mating process to produce a population of offspring with higher fitness.
3.	Mutation - changing some of the genes of the offspring randomly to maintain diversity.
4.	Fitness calculation – calculation of the fitness value for comparison with the target value and for the next iteration.
<img width="165" alt="Picture 1" src="https://user-images.githubusercontent.com/45784014/189539119-c850d619-528e-42b5-9485-c8512aa6233e.png">
<b>Fig-1</b>
<br>
<br>
<b>Branch and Bound Method</b>: In this optimal path finding method, a bound is computed for the best possible solution that can be obtained upon traversing down the current node. If the bound on this best possible solution is worse than the current best, the subtree is ignored altogether, and a different path is tried. 
<br>
<b>Dynamic Programming</b>: Dynamic programming uses recursion to break the problem into multiple sub-problems thus decreasing the time complexity and load of computation. Dynamic programming is usually used to solve NP-hard problems to bring the time complexity from exponential to polynomial.  
<br>
<b>Naïve Approach</b>: The Naïve Approach is the simplest approach which solves the problem. In this approach all possible solutions are computed, and the optimal solution is picked from the set of results. The solution can be found for sure with this approach, but it is too slow and computationally intense. The sole purpose of including this approach in the project is for baseline comparison.

### PROBLEM STATEMENT

This project aims at solving TSP with the different algorithms stated above and comparing their efficiencies based on time complexity, space complexity and optimality of solution. 

### USAGE

The files above can be used by running the tsp_generate_matrix.cpp file in the user folder to generate a random matrix for a number of cities (example 50) where the matrix elements describe the distance between two cities. The user_combine.cpp file can be run after downloading all the algorithm files to run all the four algorithms simultaneously and record the time taken by each algorithm.
Once done, the process can be repeated by changing the number of cities again and generating a seeded random matrix to feed to the four algorithms and perform multiple comparisons.

A result analysis from our side is given below for different hyperparameters and conditions for your reference:
