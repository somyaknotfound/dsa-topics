#include <bits/stdc++.h>
using namespace std;



class Solution {
    public: 
        void dfs(int v , vector <int> adj[] , vector <int> &visited , vector <int> &result ){
            
            
            visited[v] = 1;
            
            result.push_back(v);
            
            for (int u : adj[v]) {
                if (!visited[u]) {
                    dfs(u,adj,visited,result);
                }
            }
        }
        
        vector <int> bfsOfGraph(int V, vector <int> adj[]) {
            int vis[V]  = {0};
            vis[0] = 1;
            queue<int> q;
            q.push(0);
            vector <int> bfs;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            
            return bfs;
        }
};

int main() {
    int V = 5;
    
    vector <int> adj[V];
    
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};
    
    vector<int> visited(V,0);
    
    vector<int> result;
    
    Solution sol;
    
    sol.dfs(1,adj,visited,result);
    
    vector<int> bfs = sol.bfsOfGraph(V, adj);
    
    for (int x : result) cout << x << endl;
    cout << "dfs" <<endl;
    for (int x : bfs) cout << x << " ";
    
    cout << endl;
    
    return 0;
    
    
    
    
    
}
