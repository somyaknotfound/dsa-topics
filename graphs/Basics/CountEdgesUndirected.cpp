#include <bits/stdc++.h>
using namespace std;




int main() {
   int n , m;
   cin>> n>>m;
   
   vector <int> graph[n+1];
   
   for (int i = 0 ; i < m ; ++i) {
       int u ,v;
       cin>> u >> v;
       graph[u].push_back(v);
       graph[v].push_back(u);
       
   }
   
   
   int edges = 0 ;
   for (int i = 0 ;i <= n ; i++) {
       for (int child : graph[i]) {
           edges++;
       }
   }
   cout << edges/2 << endl;
    
}
