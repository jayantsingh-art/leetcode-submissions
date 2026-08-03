class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int startingRow = 0, startingCol = 0;
        int endingRow = m-1, endingCol = n-1;

        while(ans.size() < m*n) {
            for(int i = startingCol; i <= endingCol && ans.size() < m*n; i++) {
                ans.push_back(matrix[startingRow][i]);
            }
            startingRow++;

            for(int i = startingRow; i <= endingRow && ans.size() < m*n; i++) {
                ans.push_back(matrix[i][endingCol]);
            }
            endingCol--;

            for(int i = endingCol; i >= startingCol && ans.size() < m*n; i--) {
                ans.push_back(matrix[endingRow][i]);
            }
            endingRow--;

            for(int i = endingRow; i >= startingRow && ans.size() < m*n; i--) {
                ans.push_back(matrix[i][startingCol]);
            }
            startingCol++;
        }

        return ans;
    }
};