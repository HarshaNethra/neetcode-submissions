class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);

        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int srcColor, int color) {
        if(srcColor==color) return;
        
        int rows=image.size(), cols=image[0].size();
        if(sr<0 || sc<0 || sr>=rows || sc>=cols || image[sr][sc]!=srcColor)
            return;
        
        image[sr][sc]=color;
        dfs(image, sr-1, sc, srcColor, color);
        dfs(image, sr+1, sc, srcColor, color);
        dfs(image, sr, sc+1, srcColor, color);
        dfs(image, sr, sc-1, srcColor, color);
    }
};