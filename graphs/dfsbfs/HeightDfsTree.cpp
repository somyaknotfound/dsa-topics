#include <bits/stdc++.h>

using namespace std;

int dfs(int vertex , int parent , vector <vector <int>> &g ,vector <int> &subTree) {
    
    int height = 0;
    for (int child : g[vertex]) {
        if (child != parent) {
            height = max(height , 1 + dfs(child , vertex , g , subTree));
            
        }
    }
    
    subTree[vertex] = height;
    return height;
    
    // cout << "subTree[" <<vertex <<"]" <<" " << count << endl;
    
    
}




int main() {
    int n;
    cin>> n;
    vector <vector <int>> tree(n+1);
    
    for (int i = 0 ; i < n-1 ; ++i) {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    vector<int> subTree(n + 1);

    dfs(1, 0, tree, subTree);
    
    for (int i  = 1 ;i <= n ; i++) {
        cout << "Height[" << i << "] = " << subTree[i] << '\n';
    }
    
    
    
    
    
}
