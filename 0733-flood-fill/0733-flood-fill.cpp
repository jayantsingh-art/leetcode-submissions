class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];

        DFS(image, sr, sc, oldColor, color);

        return image;
    }

    void DFS(vector<vector<int>>& image, int i, int j, int oldColor, int color) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor) {
            return;
        }

        if(image[i][j] == color) return;

        image[i][j] = color;
        DFS(image, i+1, j, oldColor, color);
        DFS(image, i-1, j, oldColor, color);
        DFS(image, i, j+1, oldColor, color);
        DFS(image, i, j-1, oldColor, color);
    }
};