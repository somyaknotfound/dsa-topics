#include<bits/stdc++.h>
using namespace std;

void dfs(int v , vector <int> g[] , vector <bool> &vis) {
    vis[v] = true;
    
    
    for (int child : g[v]) {
        if (!vis[child]) {
            cout<< v << "->" << child << " ";
            dfs(child,g,vis);
        }
    }
}

int main() {
    int n , m;
    cin>> n>>m;
    vector <int> g[n+1];
    vector <bool> vis(n+1,false);
    
    for (int i = 0 ; i <m  ;++i) {
        int u , v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int cnt = 1;
    
    for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
        cout << "Component " << cnt << ": ";
        dfs(i, g, vis);
        cout << '\n';
        cnt++;
    }
}
    
    
    
    return 0;
}
