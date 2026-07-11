#include<bits/stdc++.h>
using namespace std;

void dfs(int v , vector <int> g[] , vector <bool> &vis) {
    vis[v] = true;
    
    for (int child : g[v]) {
        if (!vis[child]) {
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
    
    int cnt = 0;
    
    for (int i = 1 ;i <= n ; i++) {
        if (!vis[i]) {
            dfs(i , g,vis);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
