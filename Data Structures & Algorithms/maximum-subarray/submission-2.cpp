class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=INT_MIN;
        for(auto it:nums){
            sum+=it;
             maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
           

        }
        return maxsum;

    }
};
