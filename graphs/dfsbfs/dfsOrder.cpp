#include <bits/stdc++.h>
using namespace std;


const int N = 1e5+10;
vector <int> g[N];
bool vis[N];


void dfs(int v) {
    
    vis[v] = true;
    cout << v <<" ";
    for (int child : g[v]) {
        if (vis[child]) continue;
        
        dfs(child);
    }
    
}


int main() {
  int n , m ;
  cin>>n>>m;
  
  
 
  
  for (int i= 0 ; i < m ; ++i) {
    int u  ,v ;
    cin>> u >>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int j;
  cin>>j;
  dfs(j);
  
  
    
}
