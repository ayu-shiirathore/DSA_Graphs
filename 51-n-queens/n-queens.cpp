class Solution {
public:

    bool safe1(int row, int col, vector<string>& board, int n) {
    // Check upper-left diagonal
    int duprow = row;
    int dupcol = col;
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    
    // Check left in same row
    row = duprow;
    col = dupcol;
    while(col >= 0) {
        if(board[row][col] == 'Q') return false;
        col--;
    }
    
    // Check lower-left diagonal
    row = duprow;
    col = dupcol;
    while(row < n && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    // Base case: all columns filled
    if(col == n) {
        ans.push_back(board);
        return;
    }
    
    // Try placing queen in each row of current column
    for(int row = 0; row < n; row++) {
        if(safe1(row, col, board, n)) {
            board[row][col] = 'Q';  // Place queen
            solve(col + 1, board, ans, n);  // Recurse to next column
            board[row][col] = '.';  // Backtrack
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;

    }
};