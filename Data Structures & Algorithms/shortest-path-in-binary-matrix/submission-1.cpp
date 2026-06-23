class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int, int>> q;
        static const vector<pair<int, int>> directions= { {1,0}, {-1,0}, {0,1}, {0,-1},
                                                        {-1,-1}, {-1,1}, {1,-1}, {1,1} };
        
        q.push({0,0});
        grid[0][0]=1;

        int length=1;
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                auto [r,c]=q.front();
                q.pop();
                if(r==n-1 && c==n-1) return length;

                for(auto [dr,dc]: directions) {
                    if(r+dr<0 || c+dc<0 || r+dr>=n || c+dc>=n || grid[r+dr][c+dc])
                        continue;
                    
                    q.push({r+dr, c+dc});
                    grid[r+dr][c+dc]=1;
                }
            }
            length++;
        }
        
        return -1;
    }
};