#include<bits/stdc++.h>
using namespace std;

void dfs(int i , int j , int initialColor , int newColor , vector<vector<int>> &image) {
// 	go to all 4 sides and reject invalid edges
    int n = image.size();
    int m = image[0].size();
    


    if (i < 0 || j < 0) return;
    if (i>=n || j >= m) return;
    if (image[i][j] != initialColor) return;
    
    
    image[i][j] = newColor;
    
    
    
    dfs(i-1,j , initialColor, newColor , image);
    dfs(i+1,j , initialColor, newColor , image));
    dfs(i,j-1 , initialColor, newColor , image));
    dfs(i,j+1 , initialColor, newColor , image));


}

vector<vector<int>> floodFill(vector<vector<int>> &image,
int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
        
    if (initialColor != newColor) {
        dfs(sr,sc,initialColor , newColor , image);
    }
    
    dfs(sr,sc,initialColor , newColor , image);
    return image;

}


int main() {
    


	return 0;
}
