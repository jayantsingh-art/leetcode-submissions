class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int distance = 1;
        queue<pair<int, int>> q;

        vector<pair<int, int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        q.push({0, 0});

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1) return distance;
                for(auto dir:directions) {
                    int row = x + dir.first;
                    int col = y + dir.second;

                    if(row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 0) {
                        grid[row][col] = 1;
                        q.push({row, col});
                    }
                }
            }
            distance++;
        }
        return -1;
    }
};