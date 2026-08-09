class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<vector<int>>&ans, vector<int>&temp){
        int n=nums.size();
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        //pick
       temp.push_back(nums[idx]);
       solve(idx+1,nums,ans,temp);
       temp.pop_back();
       solve(idx+1,nums,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
         vector<int>temp;
        solve(0,nums,ans,temp);
        return ans;
        
    }
};
