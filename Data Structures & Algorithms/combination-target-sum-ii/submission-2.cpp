class Solution {
public:
    void solve(int idx,vector<int>& nums,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx==nums.size())return ;
        

        for(int i=idx;i<nums.size();i++){
            if(nums[i]>target)break;
            if(i>idx && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);

            solve(i+1,nums,target-nums[i],ans,temp);
            temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        vector<int>temp;


        solve(0,nums,target,ans,temp);
        return ans;






        
    }
};
