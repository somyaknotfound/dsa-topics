#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex , int parent , vector <vector<int>> &g , vector <int> &depth ) {
    
    
    for (int child : g[vertex]) {
        if (child != parent)
        {   depth[child] = depth[vertex] + 1;
            dfs(child , vertex , g, depth);
        }
    }
    
}







int main() {
    int n;
    cin>>n;
    
    vector <vector<int>> g(n+1);
   
    
    for (int i = 0 ; i < n-1 ; i++) {
        int u , v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    
    vector <int> depth(n+1);
    depth[1] = 0;
    dfs(1 , 0 , g,depth);
    
    for (int i = 1 ; i <= n; i++) {
        cout << depth[i] << " ";
    }
    
    
    
    
    
}
