class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse(heights.size());
        vector<int> pse(heights.size());

        stack<int> st;

        int maxArea = INT_MIN;

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            nse[i] = st.empty()?heights.size():st.top();
            st.push(i);
        }

        for(int i=0; i<heights.size(); i++){
            int width = nse[i]-pse[i]-1;
            int area = width*heights[i];
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};