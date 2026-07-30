class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < 4; i++) {
            if(mat == target) return true;
            rotate(mat);
        }

        return false;
    }

    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = i+1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }

        return mat;
    }
};