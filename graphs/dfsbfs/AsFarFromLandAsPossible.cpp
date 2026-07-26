// https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:
    vector <pair<int,int>> movements = {
        {1,0} , {-1,0} , {0,1} , {0 , -1}
    };

    bool isValid(int &i , int &j , int n) {
        return (i>=0 && j>= 0 && i < n && j < n);
    }
    int bfs(int n, vector<vector<int>>& grid ,  vector <vector <int>> &level ,  vector <vector <int>> &vis) {
        int ans = 0 ;
        queue<pair<int,int>> q;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    level[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        if (q.empty() || q.size() == n*n) {
            return -1;
        }

        while (!q.empty()) {
            auto it = q.front();
            int vx = it.first;
            int vy = it.second;

            q.pop();

            for (auto movement : movements) {
                int childx = movement.first + vx;
                int childy = movement.second + vy;

                if (isValid(childx , childy , n) && vis[childx][childy] == 0) {
                    vis[childx][childy] = 1;
                    level[childx][childy] = 1 + level[vx][vy];
                    q.push({childx , childy});
                    ans = max( ans , level[childx][childy]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector <vector <int>> vis(n , vector<int>(n , false));
        vector <vector <int>> level(n , vector <int> (n , INT_MAX));


        return bfs(n , grid, level, vis);

    }
};
