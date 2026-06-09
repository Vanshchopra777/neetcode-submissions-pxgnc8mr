class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>t;
        t.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>t.back()){
                t.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(t.begin(),t.end(),nums[i])-t.begin();

                t[idx]=nums[i];

            }
        }
        return t.size();
        
    }
};
