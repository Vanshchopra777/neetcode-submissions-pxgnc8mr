class Solution {
public:

    void solve(int ind,vector<int>&ds,int target,vector<vector<int>>&ans,vector<int>& nums){
        int n=nums.size();
       if(target == 0){
    ans.push_back(ds);
    return;
}
        
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target)break;
            ds.push_back(nums[i]);
            solve(i+1,ds,target-nums[i],ans,nums);
            ds.pop_back();


        }


    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;

        solve(0,ds,target,ans,nums);
        return ans;

        
    }
};
