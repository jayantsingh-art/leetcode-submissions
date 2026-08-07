class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int land = 0, distance = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    land++;
                }
            }
        }

        if(land == n*n || land == 0) return -1;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [x, y] = q.front();
                q.pop();
                if(land == n*n) return grid[x][y];

                int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

                for(auto dir : directions) {
                    int i = x + dir[0];
                    int j = y + dir[1];

                    if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 0) {
                        grid[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance-1;
    }
};