class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='v' || grid[i][j]=='0') continue;
                
                count++;
                dfs(grid, i, j);
            }
        }
        

        return count;
    }

    void dfs(vector<vector<char>>& grid, int sr, int sc) {
        int rows=grid.size(), cols=grid[0].size();
        if(sr<0 || sc<0 || sr>=rows || sc>=cols || grid[sr][sc]!='1') return;

        grid[sr][sc]='v';
        dfs(grid, sr-1, sc);
        dfs(grid, sr+1, sc);
        dfs(grid, sr, sc-1);
        dfs(grid, sr, sc+1);
    }
};