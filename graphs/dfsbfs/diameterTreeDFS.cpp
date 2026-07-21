#include <bits/stdc++.h>
using namespace std;

int diameter = 0;
int dfsHeight(int vertex ,int parent , vector <vector <int>> &g) {
    int largestHeight = 0;
    int secondLargest = 0;
    
        for (int child : g[vertex]) {
            if (child != parent) {
                int h =dfsHeight(child , vertex ,g) + 1;
                if (largestHeight < h ) {
                    secondLargest = largestHeight;
                    largestHeight = h;
                } else if (secondLargest < h && h < largestHeight) {
                    secondLargest = h;
                }
            }
        }
        
        diameter = max(diameter , largestHeight + secondLargest);
        
        return largestHeight ;
}




int main() {
    int n;
    cin>>n;
    
    vector <vector <int>> g(n+1);
    
    for (int i = 0 ; i < n-1 ; ++i) {
        int u , v;
        cin>>u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfsHeight(1 , 0 , g);
    
    cout << diameter << endl;
    
    
    
    
    
}
