class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>t(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int prev_i=i-1;prev_i>=-1;prev_i--){

                int nottake=t[i+1][prev_i+1];
                int take=0;
                if(prev_i==-1 || nums[i]>nums[prev_i]){
                    take=1+t[i+1][i+1];
                }
                t[i][prev_i+1]=max(take,nottake);
            }
        }
        return t[0][0];
    }
};
