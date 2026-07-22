#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex , int par ,vector <vector <int>> &tree, vector <int> & parent  , vector <int> &depth ) {
    
    parent[vertex] = par;
    
    for (int child : tree[vertex]) {
        if (child != par) {
            depth[child] = depth[vertex] + 1;
            // parent[child] = vertex; redundant as first line before entering node handles it
            dfs(child , vertex, tree, parent, depth);
        }
    }
    
}



int LCA(int u , int v , vector <int> & parent  , vector <int> &depth) {
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    
    while (depth[v] > depth[u]) {
        v = parent[v];
    }
    
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    
    return u;
}




int main() {
    int n ;
    cin>>n;
    
    vector <vector <int>> tree(n+1);
    
    for (int i = 0 ; i < n-1 ; i++) {
        
        int u , v;
        cin>> u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int q;
    cin >> q;
    vector <int> parent(n+1);
    vector <int> depth(n+1);
    depth[1] = 0;
    parent[1] = 0;
    dfs(1, 0,tree, parent, depth);
    
    while (q--) {
        int u , v;
        cin>>u>>v;
        cout << endl << LCA(u,v,parent,depth) << endl;
        
    }
}
