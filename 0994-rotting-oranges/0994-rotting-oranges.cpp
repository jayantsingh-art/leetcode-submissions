class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0, minutes = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    freshOranges++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if(freshOranges == 0) return 0;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto dir : directions) {
                    int i = x + dir[0];
                    int j = y + dir[1];

                    if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }

        return freshOranges == 0 ? minutes-1 : -1;
    }
};