#include <bits/stdc++.h>
using namespace std;




int main() {
  int n ,m;
  cin>>n>>m;
  
  vector <pair<int,int>> graph[n+1];
  
  for (int i = 0 ;i < m ; ++i) {
    int u ,  v , wt;
    cin>>u>>v>>wt;
    graph[u].push_back({v , wt});
    graph[v].push_back({u,wt});
    
     
  }
  
  for (int i = 1 ; i <= n; i++) {
      cout<< i << ": ";
      for (auto child : graph[i]) {
          cout << "(" << child.first << "," << child.second << ")" << " "; 
      }
      
      cout << endl;
  }
    
    
   
    
}
