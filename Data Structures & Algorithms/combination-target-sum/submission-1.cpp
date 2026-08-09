class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>&temp,int target,vector<vector<int>>&ans,int sum){
        if(sum==target){
            ans.push_back(temp);
            return;

        }
        if(idx == nums.size())
    return;
        if(nums[idx]<=target-sum){
            sum+=nums[idx];
            temp.push_back(nums[idx]);
            solve(idx,nums,temp,target,ans,sum);
            sum-=nums[idx];
            temp.pop_back();


        }
        solve(idx+1,nums,temp,target,ans,sum);






    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int sum=0;
        vector<int>temp;

        solve(0,nums,temp,target,ans,sum);
        return ans;


        
    }
};
