class Solution {
public:
int roblinear(int start,int end,vector<int>& nums) {

        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for(int i = end; i >= start; i--) {

            int curr = max(nums[i] + next2,
                           next1);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        return max(roblinear(0,n-2,nums),roblinear(1,n-1,nums));
        
    }
};
