class Solution {
private:
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& mat, int delrows[], int delcols[]){
    vis[row][col]=1;
    int n=mat.size();
    int m= mat[0].size();

    //check for top,right,botton,left
    for(int i=0;i<4;i++){
        int nrow = row + delrows[i];
        int ncol = col + delcols[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
            dfs(nrow, ncol, vis, mat, delrows, delcols);
        }
    }
}
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrows[] = {-1,0,1,0};
        int delcols[] = {0,1,0,-1};

        //traverse first and last row and perform dfs on boundary 0s
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat, delrows, delcols);
            }
            //last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat, delrows, delcols);
            }
        }

        //traverse first and last column and perform dfs on boundary 0s
        for(int i=0;i<n;i++){
            //first column
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat, delrows, delcols);
            }
            //last column
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat, delrows, delcols);
            }
        }

        //traverse whole matrix for remaining zeros and convert them to X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                mat[i][j]='X';
            }
        }
    }
};