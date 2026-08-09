class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            temp.push_back(nums[idx]);
            solve(idx+1,nums,ans,temp);
            swap(nums[idx],nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;


        solve(0,nums,ans,temp);
        return ans;
        
    }
};
