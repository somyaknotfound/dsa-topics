class Solution {
public:
    void dfs(int x , int y,vector <vector <bool>> &vis , vector<vector<char>>& board , int n , int m ) {
        vis[x][y] = true;
        
        int dx[2] = {1,0};
        int dy[2] = {0,1};

        for (int i = 0 ; i < 2 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 'X') {
                dfs(nx,ny, vis , board , n , m);
            }

        }

        

    }


    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector <vector <bool>> vis(n , vector <bool>(m , false));
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (!vis[i][j] && board[i][j] == 'X') {
                    cnt++;
                    dfs(i , j , vis , board , n , m);
                }
            }
        }

        return cnt;
    }
};
