class Solution {
public:
    void solve(int start,vector<int>&temp,vector<vector<int>>&ans,vector<int>& nums){
        ans.push_back(temp);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            solve(i+1,temp,ans,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,temp,ans,nums);
        return ans;

        
    }
};
