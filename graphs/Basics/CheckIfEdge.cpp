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
   
   int u1,v1;
   cin>> u1>>v1;
   bool yes = false;
   for (int child : graph[u1]) {
       if (child == v1) {
           yes = true;
           break;
       }
   }
   
   if (yes) {
       cout << "YES";
   } else {
       cout<< "NO";
   }
    
    
   
    
}
