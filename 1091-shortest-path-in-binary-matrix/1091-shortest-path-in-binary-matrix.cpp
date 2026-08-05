class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 1;
        queue<pair<int, int>> q;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        int directions[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        q.push({0, 0});

        while(!q.empty()) {

            int size = q.size();

            while(size--) {
                auto [x, y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1) return ans;

                for(auto dir : directions) {
                    int newRow = x + dir[0];
                    int newCol = y + dir[1];

                    if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && grid[newRow][newCol] == 0) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 1;
                    }
                }
            }
            ans++;
            // cout << ans << endl;
        }
        return -1;
    }
};