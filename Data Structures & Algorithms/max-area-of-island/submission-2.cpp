class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    maxArea=max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int ROWS=grid.size();
        int COLUMNS=grid[0].size();

        if(min(r,c)<0 || r==ROWS || c==COLUMNS 
           || grid[r][c]==0 
           || grid[r][c]==2)
           return 0;
        
        grid[r][c]=2;

        return 1+ dfs(grid, r+1, c) + dfs(grid, r-1, c)
               + dfs(grid, r, c-1) + dfs(grid, r, c+1);
    }
};