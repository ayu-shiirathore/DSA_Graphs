class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;

        vector<vector<int>>dist(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && dist[nrow][ncol]==-1){
                    dist[nrow][ncol]=dist[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return dist;
    }
};