#include <bits/stdc++.h>
using namespace std;



 
int main() {
    
    int n , m;
    cin>>n>>m;
    
    vector <int> graph[n+1];
    
    for (int i = 0 ;i < m ; ++i) {
        int u , v;
        cin>> u  >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    
    int maxCount = 0;
    int MaxVertex = 0;
    
    for (int i = 1; i <= n ; i++) {
        int count = 0;
        int vertex = i;
        for (int child : graph[i]) {
            count++;
        }
        
        if (count > maxCount) {
            MaxVertex = vertex;
            maxCount = max(count , maxCount);
        }
    }
    
    cout << MaxVertex << endl;
    
    
}
