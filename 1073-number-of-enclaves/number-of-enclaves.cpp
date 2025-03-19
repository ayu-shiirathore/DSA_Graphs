class Solution {
private:
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
    vis[row][col]=1;
    int n = grid.size();
    int m = grid[0].size();
    int delrows[] = {-1,0,1,0};
    int delcols[] = {0,1,0,-1};

    //check for top,right,botton,left
    for(int i=0;i<4;i++){
        int nrow = row + delrows[i];
        int ncol = col + delcols[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
            dfs(nrow, ncol, vis, grid);
        }
    }
}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        //traverse first and last row for boundary 1's
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j]==1)
            dfs(n-1,j,vis,grid);
        }

        //traverse first and last colums for boundary 1,s and perform dfs on all connected 1's
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && grid[i][0]==1)
            dfs(i,0,vis,grid);
            //last col
            if(!vis[i][m-1] && grid[i][m-1]==1)
            dfs(i,m-1,vis,grid);
        }

        int count=0;

        //now check for remaining 1's that are neither boundary 1's nor connected to boundary 1's
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(!vis[i][j] && grid[i][j]==1)
                count++;
            }
        }

        return count;
        
    }
};