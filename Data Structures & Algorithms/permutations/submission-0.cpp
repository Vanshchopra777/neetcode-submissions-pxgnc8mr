class Solution {
public:
    void solve(int start,vector<vector<int>>&ans,vector<int>& nums){
        unordered_set<int>mpp;

        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp.insert(nums[i]);

                swap(nums[start],nums[i]);
                solve(start+1,ans,nums);
                swap(nums[start],nums[i]);


            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>temp;

        solve(0,ans,nums);

        return ans;
        

        
    }
};
