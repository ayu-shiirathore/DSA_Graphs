class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m=image.size();
        int n=image[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});
        int originalColor=image[sr][sc];
        if(color==originalColor) return image;
        image[sr][sc]=color;

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==originalColor){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;

    }
};