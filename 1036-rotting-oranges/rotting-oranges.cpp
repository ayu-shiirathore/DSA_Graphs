class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0, rotten = 0;
        queue <pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(m,vector<int> (n,-1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] ==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int rows[] = {-1,0,1,0};
        int cols[] = {0,1,0,-1};
        int time =0;

        while(!q.empty()){
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            time = it.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r + rows[i];
                int ncol = c + cols[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    grid[nrow][ncol]=2;
                    rotten++;
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }

        return rotten!=fresh?-1:time;
    }
};