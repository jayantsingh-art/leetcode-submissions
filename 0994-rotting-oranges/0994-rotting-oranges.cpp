class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0, minutes = 0;

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
        if(q.empty()) return -1;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int size = q.size();
            // cout << "Queue size = " << size << endl;
            while(size--) {
                auto [row, col] = q.front();
                q.pop();
                // cout << "Processing (" << row << "," << col << ")" << endl;
                for(auto dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshOranges--;
                        // cout << "Fresh: " << freshOranges << endl;
                    }
                }
            }
            minutes++;
        }
        return freshOranges == 0 ? minutes-1 : -1;
    }
};