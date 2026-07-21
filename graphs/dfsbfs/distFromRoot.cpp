#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex , int parent , vector <vector <pair <int,int>>> &g , vector <int> &dist) {
    
    
    for (auto child : g[vertex]) {
        if (child.first != parent)
        {   dist[child.first] = dist[vertex] + child.second;
            dfs(child.first , vertex , g, dist);
        }
    }
    
}







int main() {
    int n;
    cin>>n;
    
    vector <vector < pair <int, int>>> g(n+1);
   
    
    for (int i = 0 ; i < n-1 ; i++) {
        int u , v , w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        
    }
    
    vector <int> dist(n+1);
    dist[1] = 0;
    
    dfs(1, 0,g , dist);
    
    for (int i = 1 ; i <= n; i++) {
        cout << dist[i] << " ";
    }
    
    
    
    
    
}
