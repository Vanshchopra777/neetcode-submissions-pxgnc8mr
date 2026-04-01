class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
                unordered_set<int> seen;
            for(int j=i+1;j<n;j++){
                int target=-(nums[i]+nums[j]);
                if(seen.count(target)){
                    vector<int>temp={nums[i],nums[j],target};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);

                }
                seen.insert(nums[j]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
