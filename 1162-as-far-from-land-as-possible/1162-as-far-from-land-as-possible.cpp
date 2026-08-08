class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int land = 0, distance = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    land++;
                }
            }
        }

        if(land == 0 || land == n*n) {
            return -1;
        }

        int directions[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};

        while(!q.empty()) {
            int size = q.size();

            if(land == n*n) return distance;

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto dir : directions) {
                    int i = x + dir[0];
                    int j = y + dir[1];

                    if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0) {
                        q.push({i, j});
                        grid[i][j] = 1;
                        land++;
                    }
                }
            }
            distance++;
        }

        return -1;
    }
};