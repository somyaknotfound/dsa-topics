#include <bits/stdc++.h>
using namespace std;



class Solution {
    
    private:
        void dfs(int node,vector<int> adjList[] , int visited[]) {
            visited[node] = 1;
            
            for (auto neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    dfs(neighbour,adjList,visited);
                }
            }
        }
    public: 
        int numProvinces(vector<vector<int>> adj,  int V) {
            vector <int> adjList[V];
            
            // convert matrix intro adjList
            for (int i = 0 ; i < V; i++) {
                for (int j = 0 ; j < V ; j++) {
                    if (adj[i][j] == 1 && i != j){
                        adjList[i].push_back(j);
                        adjList[j].push_back(i);
                        
                    }
                }
            }
            
            int visited[V] = {0};
            
            int count = 0;
            
            for (int i = 0 ; i < V ; i++) {
                if (!visited[i]) {
                    count++;
                    dfs(i , adjList , visited);
                }
            }
            
            return count;
        }
};
        

int main() {
    // Adjacency matrix input
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Number of vertices
    int V = 3;

    // Create object of Solution
    Solution obj;

    // Call the function and print result
    cout << obj.numProvinces(adj, V) << endl;

    return 0;
}
