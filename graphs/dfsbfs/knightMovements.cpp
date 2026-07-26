#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int vis[8][8];
int lev[8][8];




int getX(string sr) {
    return sr[0]-'a';
}

int getY(string dst) {
    return dst[1] - '1';
}

bool isValid(int x , int y) {
    return x>=0 && y>=0 && x< 8 && y < 8;
}

vector <pair<int,int>> movements = {
    {-1,2} , {1,2} ,
    {-1,-2} , {1,-2},
    {2,-1} , {2,1},
    {-2,-1} ,{-2 , 1}
};

int bfs(string sr , string dst) {
    int sourceX = getX(sr);
    int sourceY = getY(sr);
    
    int dstX = getX(dst);
    int dstY = getY(dst);
    
    queue <pair<int,int>> q;
    q.push({sourceX , sourceY});
    vis[sourceX][sourceY] = 1;
    lev[sourceX][sourceY] = 0;
    
    
    
    while (!q.empty()) {
        pair<int,int> v = q.front();
        int x = v.first , y = v.second;
        q.pop();
        
        if (x == dstX && y == dstY) break;
        
        for (auto movement : movements) {
            int childX = movement.first + x;
            int childY = movement.second + y;
            
            if (isValid(childX,childY) && vis[childX][childY] == 0) {
                q.push({childX,childY});
                vis[childX][childY] = 1;
                lev[childX][childY] = lev[x][y] + 1;
            }
        }
        
    }
    
    return lev[dstX][dstY];
    
    
    
    
}

void reset() {
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            lev[i][j] = 0;
            vis[i][j]=0;
        }
    }
}

int main() {
    int n ;
    cin>>n;
    while (n--) {
        reset();
        string s1,s2;
        cin>>s1>>s2;
        cout << bfs(s1,s2) << endl;
        
    }
    
    return 0;
}
