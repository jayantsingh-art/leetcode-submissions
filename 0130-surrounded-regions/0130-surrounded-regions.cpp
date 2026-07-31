class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1)) {
                    DFS(board, i, j);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

    void DFS(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }

        if(board[i][j] == 'X' || board[i][j] == 'T') return;

        board[i][j] = 'T';
        DFS(board, i+1, j);
        DFS(board, i-1, j);
        DFS(board, i, j+1);
        DFS(board, i, j-1);
    }
};