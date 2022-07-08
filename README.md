# Introduction
Program to find the shortest path from a given source node to other nodes. \
Used Dijikstra algorithm to get the output. The output is optimal in terms of memory and space requirements. 
# Complexity
Time Complexity - O((n+e)log(n)) \
Space Complexity - O(n) \
where n is the number of nodes and e is the number of edges

# Assumptions
 - Directed acylic Graph (DAG)
 - All edge values are positive
 - Maximum distance of a node from the source is less than 2^31-1(INT sotrage capacity)
 - n is less than (2^31-1)
 - nodes are in the form of 0,1 ... n-1

where n is the number of nodes and e is the number of edges 

# Usage
```
$ g++ assignment.cpp -o assignment
$ assignment
```
