class Solution {
public:
    void dfs(int v, vector<vector<int>> &g, vector<bool> &vis) {
        vis[v] = true;

        for (int child : g[v]) {
            if (!vis[child])
                dfs(child, g, vis);
        }
    }

    int countConnected(int V, vector<vector<int>>& edges) {

        vector<vector<int>> g(V);
        vector<bool> vis(V, false);

         for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, g, vis);
                cnt++;
            }
        }

        return cnt;
    }
};
