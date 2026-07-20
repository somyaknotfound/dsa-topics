#include <bits/stdc++.h>
using namespace std;


void bfs(int vertex , vector <int> g[] , vector <bool> &vis) {
    queue <int> q;
    vis[vertex] = true;
    q.push(vertex);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << endl;
        
        for (int nbr : g[node]) {
            if (!vis[nbr]) {
                vis[nbr] = true;
                q.push(nbr);
            }
        }
    }
}


int main() {
    int n,m;
    cin>>n>>m;
    
    vector <int> graph[n];
    
    for (int i = 0 ; i < m ; ++i) {
        int u , v;
        cin>> u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector <bool> vis(n , false);
    
    bfs(0 , graph , vis);
    
}
