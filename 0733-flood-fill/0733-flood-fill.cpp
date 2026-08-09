class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        DFS(image, sr, sc, color, oldColor);

        return image;
    }

    void DFS(vector<vector<int>>& image, int i, int j, int color, int oldColor) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor) {
            return;
        }

        if(image[i][j] == color) return;

        image[i][j] = color;

        DFS(image, i+1, j, color, oldColor);
        DFS(image, i-1, j, color, oldColor);
        DFS(image, i, j+1, color, oldColor);
        DFS(image, i, j-1, color, oldColor);
    }
};