class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int distance = 1;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        int directions[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        q.push({0, 0});

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto[x, y] = q.front();
                q.pop();

                if(x == n-1 && y == n-1) return distance;

                for(auto dir : directions) {
                    int i = x + dir[0];
                    int j = y + dir[1];

                    if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0) {
                        grid[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }

        return -1;
    }
};