class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, DFS(grid, i, j));
                }
            }
        }

        return ans;
    }

    int DFS(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;
        return 1 +
            DFS(grid, i+1, j) +
            DFS(grid, i-1, j) +
            DFS(grid, i, j+1) +
            DFS(grid, i, j-1);
    }
};