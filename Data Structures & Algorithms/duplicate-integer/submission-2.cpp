class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it]>1)return true;
        }
        // for(auto it:mpp){
        //     if(it.second>1)return true;
        // }
        return false;
   
        
    }
};