class Solution {
  public:
  
    bool dfs(int v , vector <bool> &vis , vector <int> g[] , int parent) {
        vis[v] = true;
        
        for (int child : g[v]) {
            if (!vis[child]) {
                if (dfs(child , vis , g, v)) {
                    return true;
                }
            } else if (child != parent) {
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector <int> graph[V];
        vector <bool> vis(V , false);
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        
        for (int i = 0 ; i < V ; i++) {
            if (!vis[i]) {
                if (dfs(i  , vis, graph , -1)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
