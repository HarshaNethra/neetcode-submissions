class Solution {
public:
    queue<pair<int, int>> q;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0)
                    q.push({i,j});
            }
        }

        bfs(grid);
    }

    void bfs(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ROWS=grid.size(), COLS=grid[0].size();

        int length=0;
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                int r=q.front().first; int c=q.front().second;
                q.pop();

                if(grid[r][c]!=0)
                    grid[r][c]=min(grid[r][c], length);
                
                int neighbours[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                for(int j=0;j<4;j++) {
                    int newR=r+neighbours[j][0], newC=c+neighbours[j][1];

                    if(min(newR,newC)<0 || newR>=ROWS || newC>=COLS || 
                        visited[newR][newC] || grid[newR][newC]==-1 || 
                        grid[newR][newC]==0)
                        continue;
                    
                    q.push(pair<int, int>(newR, newC));
                    visited[newR][newC]=1;
                }
            }
            length++;
        }
    }
};
