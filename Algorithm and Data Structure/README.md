# Algorithm and Data Structure

In this repository, you'll find a collection of codes that I developed during the discipline of algorithm and data structure.

## Dijkstra's Algorithm
This code implements Dijkstra's algorithm for finding the shortest path in a graph with non-negative edge weights.

### Input
The input to the program is specified in the form of an adjacency matrix grafo, which is defined at the beginning of the code. The size of the matrix is set to `GRAPH_SIZE` (which is currently set to 7).

### Output
The output of the program is the minimum cost to reach each vertex from the starting vertex (which is set to 0 in the main function). The minimum costs are printed to the console.

## Linked List
This code is an implementation of a linked list data structure in C++. The linked list is a doubly-linked list, meaning that each node has pointers to both the next and previous nodes in the list.

### Features
The linked list implementation includes the following functions:

- `insert`: Inserts an element at the beginning of the list. <br>
- `insertEnd`: Inserts an element at the end of the list. <br>
- `remove`: Removes the first element of the list. <br>
- `removeEnd`: Removes the last element of the list. <br>
- `removeElement`: Removes a specified element from the list. <br>
- `print`: Prints the elements of the list to the console. <br>

## MinHeap
This code is an implementation of a min-heap data structure in C++. The heap is a complete binary tree that satisfies the heap property, which states that the value of each node is greater than or equal to the values of its children.

### Features
The heap implementation includes the following functions:

- `push`: Inserts an element into the heap.
- `pop`: Removes the top element of the heap.
- `top`: Returns the top element of the heap.
- `empty`: Returns `true` if the heap is empty, `false` otherwise.
- `full`: Returns `true` if the heap is full, `false` otherwise.
- `print`: Prints the elements of the heap to the console.

## Stack
This particular code is a solution to the problem of checking if a given sequence of parentheses/braces is well-formed. It uses a stack data structure to keep track of the opening parentheses/braces and checks if they have a corresponding closing parentheses/braces in the correct order.

The code includes the following functions:

- `push`: inserts an element into the top of the stack.
- `pop`: removes the top element from the stack.
- `empty`: checks if the stack is empty.
- `top`: returns the element at the top of the stack.
- `verifica`: takes in a string as input and returns true if the sequence is well-formed and false otherwise.

## Topological Sort

### How it works
The code uses a graph data structure to represent the order of the clothes. Each vertex represents a piece of clothing, and the edges represent the order in which the clothes must be worn. For example, if there is an edge from vertex A to vertex B, it means that the piece of clothing represented by vertex A must be worn before the piece of clothing represented by vertex B.

The code uses a depth-first search (DFS) algorithm to traverse the graph and find the topological order of the clothes. The algorithm starts at a vertex and explores as far as possible along each branch before backtracking. In this way, the algorithm is able to visit all the vertices of the graph and find the order in which the clothes should be worn.

### Usage
To use the code, you need to initialize the adjacency list `adj` and the dictionary `dicionario`. The adjacency list represents the graph, with each element of the list representing a vertex and the elements within the list representing the edges. The dictionary is used to store the names of the clothes, with the key representing the vertex and the value representing the name of the clothing.

Once these data structures have been initialized, you can call the `dfs_explore` function to find the topological order
