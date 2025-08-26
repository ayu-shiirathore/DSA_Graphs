class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSq = 0;
        int maxArea = 0;
        
        for(int i = 0; i < dimensions.size(); i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            
            // Calculate diagonal squared (avoiding sqrt for comparison)
            int diagonalSq = length * length + width * width;
            int area = length * width;
            
            if(diagonalSq > maxDiagonalSq) {
                // Found a rectangle with longer diagonal
                maxDiagonalSq = diagonalSq;
                maxArea = area;
            } else if(diagonalSq == maxDiagonalSq) {
                // Same diagonal length, take the rectangle with larger area
                if(area > maxArea) {
                    maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
};