void dfs(int v) {
    
    vis[v] = true;
    cout << "Enter" << v <<" " << endl;
    for (int child : g[v]) {
        if (vis[child]) continue;
        
        dfs(child);
    }
    cout << "Exit" << v <<" "<< endl;
    
}
