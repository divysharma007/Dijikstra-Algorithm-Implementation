#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Takes input and forms the adjacency list
 * @param numberOfNodes number of nodes in the graph
 * @param numberOfEdges number of total edges in the graph
 * @return Adjacency list containing neightbours of each node
 */
vector<vector<pair<int,int>>> getNeighbours(int numberOfNodes,int numberOfEdges){
  vector<vector<pair<int,int>>>neighbours(numberOfNodes);
  cout << "Provide all the edges which are present in the graph" << endl;
  cout << "Provide inputs as: <Parent> <Child> <Edge value>" << endl;
  for (int i = 0; i < numberOfEdges; i++)
  {
      int parentNode, childNode, edgeValue;
      cin >> parentNode >> childNode >> edgeValue;
      neighbours[parentNode].push_back({edgeValue, childNode});
   }
   return neighbours;
}

/**
 * @brief Uses dijkstra algorithm and finds the shortest distance of all the nodes from the source node
 * @param sourceNode Node from which distances are to be found
 * @param neighbours List contaning neighbours to which the
 * @return returns the shortest distance of all nodes from the source node
 */
vector<int> findShortestPath(int sourceNode,vector<vector<pair<int,int>>> neighbours){
int numberOfNodes=neighbours.size();
 vector<int>distanceVector(numberOfNodes,INT_MAX);
 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
   pq.push({0,sourceNode});
   while(!pq.empty()){
       int node=pq.top().second,
       distance=pq.top().first;
       pq.pop();
       distanceVector[node]=min(distanceVector[node],distance);
       for(int child=0;child<neighbours[node].size();child++){
           pq.push({distance+neighbours[node][child].first, neighbours[node][child].second});
       }
   }
   return distanceVector;
}
/**
 * @brief Prints the shortest distance of node from the source node
 * @param distanceVector Vector storing shortest distance 
 */
void printOutput(vector<int>distanceVector){
int numberOfNodes=distanceVector.size();
   for(int node=0;node<numberOfNodes;node++)
       cout << "Shortest distance of node " <<node <<" from the source node is " <<distanceVector[node] << endl;
   
}
int main()
{
    int numberOfNodes,numberOfEdges,sourceNode;
    cout<< "Provide the number of nodes, edges and the source node which are present in the graph" <<endl;
    cout<< "Provide input as: <Number of node> <Number of edges> <source node>" <<endl;
    cin>>numberOfNodes>>numberOfEdges>>sourceNode;
    vector<vector<pair<int,int>>> neighbours=getNeighbours(numberOfNodes,numberOfEdges);
    vector<int>distanceVector=findShortestPath(sourceNode,neighbours);
    printOutput(distanceVector);

    return 0;
}
