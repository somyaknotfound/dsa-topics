#include <bits/stc++.h>
using namespace std;

const int N = 1e3+10;
const int INF= 1e9+10;

int val [N][N];
int vis[N][N];
int lev[N][N;
int n,m;

vector <pair<int,int>> movements = {
    {0,1} , {0,-1} , {1,0} , {-1,0}
};


bool isValid(int i, int j) {
    return (i>=0 && i < n && j>=0 && j<m) ;
}

int bfs() {
    int mx = 0;
    
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            mx = max(mx , val[i][j]);
            
        }
    }
    queue <pair<int,int>> q;
    // grid dealing with pairs
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            if (mx == val[i][j]) {
                q.push({i,j});
                lev[i][j] = 0;
                // starting node
                vis[i][j] = 1;
            }
            
        }
    }
    
    while(!q.empty()) {
        auto it = q.front();
        int v_x = it.first;
        int v_y = it.second;
        q.pop();
        
        for (auto movement : movements) {
            int child_x = movement.first+v_x;
            int child_y = movement.second+v_y;
            
            if (isValid(child_x , child_y) && vis[child_x][child_y] == 0) {
                lev[child_x][child_y] = 1 + lev[v_x][v_y];
                vis[child_x][child_y] = 1;
                q.push({child_x,child_y});
            }
        }
        
        
        
        
    }
    
    
}


void reset() {
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for (int i = 0 ;  i < n ; ++i) {
            for (int j = 0  ;  j < m ; ++j) {
                cin>>val[i][j];
            }
        }
        cout << bfs() << endl;
        
    }
}
