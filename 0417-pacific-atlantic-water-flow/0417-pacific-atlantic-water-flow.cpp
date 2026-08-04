class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));

        //first column
        for(int i = 0; i < m; i++) {
            DFS(heights, pacific, i, 0);
        }

        //first row
        for(int j = 0; j < n; j++) {
            DFS(heights, pacific, 0, j);
        }

        //last column
        for(int i = m-1; i >= 0; i--) {
            DFS(heights, atlantic, i, n-1);
        }

        //last row
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

        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for(auto dir : directions) {
            int newRow = i + dir.first;
            int newCol = j + dir.second;

            if(newRow >= 0 && newCol >= 0 && newRow < heights.size() && newCol < heights[0].size() && heights[newRow][newCol] >= heights[i][j]) {
                DFS(heights, visited, newRow, newCol);
            }
        }
    }
};