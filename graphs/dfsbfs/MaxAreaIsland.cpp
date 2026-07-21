class Solution {
public:
    int dfs(int x , int y , vector <vector <bool>> &vis , vector<vector<int>>& grid , int n , int m) {
        
        vis[x][y] = true;
        int area = 1;


        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx>= 0 && nx < n && ny>= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 1) {
                area += dfs(nx,ny,vis,grid , n,m);

            }
        }

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector <vector <bool>> vis(n , vector<bool> (m , false));
        int maxArea = 0;

        
        
        

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    
                    maxArea = max(maxArea ,  dfs(i , j , vis , grid , n , m));
                   
                }
            }
        }

        return maxArea;

    }
};
