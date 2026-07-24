#include <bits/stdc++.h>
using namespace std;


void bfs(int vertex , vector <vector <int>> graph , vector <bool> &vis) {
    queue <int> q;
    
    vis[vertex] = true;
    q.push(vertex);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << "->";
        
        for (int child : graph[node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}



int main() {
    int n,m;
    
    cin>>n>>m;
    vector <vector <int>> graphs(n+1);
    
    for (int i = 0 ; i < m ; ++i) {
        int u , v;
        cin>>u>>v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }
    
    vector <bool> vis(n+1 , false);
    
    for (int i = 1;  i <= n ; i++) {
        if (!vis[i]) {
            bfs(i , graphs , vis);
        }
        cout << endl;
    }
    
    return 0;
    
}
