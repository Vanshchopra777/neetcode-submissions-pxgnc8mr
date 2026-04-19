class Solution {
public:
    void solve(int ind,vector<int>&ds,int target,vector<int>& nums,vector<vector<int>>&ans){
        int n=nums.size();
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
              
            }
              return;
        }
        
        if(nums[ind]<=target){
            ds.push_back(nums[ind]);
            solve(ind,ds,target-nums[ind],nums,ans);
            ds.pop_back();
        }
         solve(ind+1,ds,target,nums,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>>ans;
        vector<int>ds;

        solve(0,ds,target,nums,ans);
        return ans;
    }
};
