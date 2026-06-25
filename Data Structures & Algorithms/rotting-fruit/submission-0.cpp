class Solution {
public:
    inline static const vector<pair<int, int>> directions= {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> freshToBeRot;

        int time=0;
        while(true) {
            freshToBeRot.clear();
            for(int i=0;i<grid.size();i++) {
                for(int j=0;j<grid[0].size();j++) {
                    if(grid[i][j]==0 || grid[i][j]==2) continue;
                    
                    if(canBeRotted(grid, i, j)) freshToBeRot.push_back({i,j});
                }
            }

            if(freshToBeRot.empty()) {
                break;
            }

            for(auto [i,j]:freshToBeRot) grid[i][j]=2;
            time++;
        }

        for(int i=0;i<grid.size();i++) {
                for(int j=0;j<grid[0].size();j++) {
                    if(grid[i][j]==1) return -1;
                }
            }

        return time;
    }

    bool canBeRotted(vector<vector<int>>& grid, int i, int j) {
        bool valid=false;
        for(auto [dr,dc]: directions) {
            int nr=i+dr, nc=j+dc;
            int rows=grid.size(), columns=grid[0].size();
            if(nr<0 || nc<0 || nr>=rows || nc>=columns) continue;

            if(grid[nr][nc]==2) {
                valid=true;
                break;
            }
        }

        return valid;
    }
};