class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans; 

        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));

        for(int i = 0; i < m; i++) {
            DFS(heights, pacific, i, 0);
        }

        for(int j = 0; j < n; j++) {
            DFS(heights, pacific, 0, j);
        }

        for(int i = m-1; i >= 0; i--) {
            DFS(heights, atlantic, i, n-1);
        }

        for(int j = n-1; j >= 0; j--) {
            DFS(heights, atlantic, m-1, j);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        if(visited[i][j]) return;

        visited[i][j] = true;

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for(auto dir : directions) {
            int row = i + dir[0];
            int col = j + dir[1];

            if(row >= 0 && col >= 0 && row < heights.size() && col < heights[0].size() && heights[row][col] >= heights[i][j]) {
                DFS(heights, visited, row, col);
            }
        }
    }
};