class Solution {
public:
    bool isValid(int &i , int &j , int n , int m , vector<vector<char>>& maze) {
        return (i>= 0 && j>= 0 && i < n && j < m && maze[i][j] == '.');
    }

    bool isExit(int &i , int &j,int n, int m , vector<vector<char>>& maze) {
        return ((i==0 || j == 0 || (i== n -1)|| (j==m-1)));
    }

    vector <pair<int,int>> movements = {
        {1,0} , {-1,0} , {0,1} , {0,-1}
    };


    int bfs(vector<vector<char>>& maze , vector <vector <bool>> &vis ,vector <vector <int>> &level  , int n, int m , int x, int y) {
        vis[x][y]= true;
        level[x][y] = 0;
        queue<pair<int,int>>q;
        int ans = INT_MAX;
        q.push({x,y});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int vx = it.first;
            int vy = it.second;

            for (auto move :movements) {
                int cx = move.first + vx;
                int cy = move.second + vy;

                if(isValid(cx,cy , n , m ,maze) && vis[cx][cy] == 0) {
                    vis[cx][cy] = 1;
                    level[cx][cy] = 1 + level[vx][vy];
                    q.push({cx,cy});
                    if (isExit(cx,cy,n,m,maze)) {
                        return level[cx][cy];
        
                    }
                }
            }
        }
        

        return -1;
    }



    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int x = entrance[0];
       int y = entrance[1];

       int n = maze.size();
       int m = maze[0].size();

       vector <vector <bool>> vis(n , vector<bool>(m ,false));
    vector <vector <int>> level(n , vector<int>(m , INT_MAX));

    return bfs(maze , vis , level , n , m , x ,  y);


    }
};
