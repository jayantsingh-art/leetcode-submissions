class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        DFS(image, oldColor, color, sr, sc);

        return image;
    }

    void DFS(vector<vector<int>>& image, int oldColor, int color, int i, int j) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor) {
            return;
        }

        if(color == oldColor) return;
        
        image[i][j] = color;
        DFS(image, oldColor, color, i+1, j);
        DFS(image, oldColor, color, i-1, j);
        DFS(image, oldColor, color, i, j+1);
        DFS(image, oldColor, color, i, j-1);
    }
};