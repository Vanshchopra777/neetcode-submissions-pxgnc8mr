class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }
        vector<vector<int>>bucket(n+1);

        for(auto it: mpp){
            int num=it.first;
            int freq=it.second;
            bucket[freq].push_back(num);
        }
        vector<int>ans;
        for(int i=n;i>=1 && ans.size()<k;i--){
           for(auto it:bucket[i]){
            ans.push_back(it);
            if(ans.size()==k)break;
           }
        }
       return ans;

    }
};
