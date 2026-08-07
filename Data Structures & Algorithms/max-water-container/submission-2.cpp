class Solution {
public:
    int maxArea(vector<int>& heights) {

        //think greedy
        int n=heights.size();

        int i=0;
        int j=n-1;
        int maxwater=0;
        int  water=0;

        while(i<j){
        water=(j-i)*min(heights[i],heights[j]);

        if(heights[i]<heights[j])i++;
        else j--;
        maxwater=max(maxwater,water);

        }
        
        return maxwater;
    }
};
