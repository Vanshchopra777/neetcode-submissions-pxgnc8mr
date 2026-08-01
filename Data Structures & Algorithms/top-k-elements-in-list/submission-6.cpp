class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }

        vector<vector<int>>bucket(n+1);//[0,n]
        vector<int>ans;

        for(auto it:mpp){
            bucket[it.second].push_back(it.first);
        }
        for(int i=n;i>=1 && ans.size()<k;i--){
            for(auto it:bucket[i]){
                ans.push_back(it);
            }
        }
        

      
        return ans;
        
    }
};
