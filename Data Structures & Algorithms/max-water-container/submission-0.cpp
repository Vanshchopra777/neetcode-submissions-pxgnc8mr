class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        int area=0;
        int i=0;
        int j=n-1;
        while(i<j){
            area=(j-i)*min(heights[i],heights[j]);
            maxarea=max(maxarea,area);

            if(heights[i]<=heights[j])i++;
            else j--;
        }
        return maxarea;

        
    }
};
