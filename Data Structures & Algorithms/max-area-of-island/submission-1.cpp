class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0 || grid[i][j]==2) continue;

                maxArea=max(maxArea, dfs(grid, i, j));
            }
        }
        
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int sr, int sc) {
        int rows=grid.size(), cols=grid[0].size();
        if(sr<0 || sc<0 || sr>=rows || sc>=cols || grid[sr][sc]!=1) return 0;

        grid[sr][sc]=2;

        return 1 + dfs(grid,sr-1,sc) + dfs(grid,sr+1,sc)
                 + dfs(grid,sr,sc-1) + dfs(grid,sr,sc+1);
    }
};