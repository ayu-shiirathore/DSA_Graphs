class Solution {
public:
    vector<int> drow = {0, 1, 0, -1};
    vector<int> dcol = {-1, 0, 1, 0};
    
    bool helper(int x, int y, int id, vector<vector<char>>& board, string &word, vector<vector<bool>>& visited) {
        if(board[x][y] != word[id]) return false;
        if(id == word.size() - 1) return true;
        
        int n = board.size();
        int m = board[0].size();
        
        visited[x][y] = true;  // Mark as visited
        
        for(int i = 0; i < 4; i++) {
            int r = x + drow[i];
            int c = y + dcol[i];
            
            if(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                if(helper(r, c, id + 1, board, word, visited)) {
                    return true;
                }
            }
        }
        
        visited[x][y] = false;  // Backtrack: unmark
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(helper(i, j, 0, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};