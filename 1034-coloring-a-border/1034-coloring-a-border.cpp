class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int originalColor = grid[row][col];
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int,int>> border;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        // DFS using an explicit stack
        vector<pair<int,int>> stack;
        stack.push_back({row, col});
        visited[row][col] = 1;
        
        while (!stack.empty()) {
            auto [r, c] = stack.back();
            stack.pop_back();
            
            bool isBorder = false;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    // boundary of grid
                    isBorder = true;
                } else if (grid[nr][nc] != originalColor) {
                    // adjacent cell not in component
                    isBorder = true;
                } else if (!visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    stack.push_back({nr, nc});
                }
            }
            
            if (isBorder) {
                border.push_back({r, c});
            }
        }
        
        // Apply the color to all border cells
        for (auto& [r, c] : border) {
            grid[r][c] = color;
        }
        
        return grid;
    }
};