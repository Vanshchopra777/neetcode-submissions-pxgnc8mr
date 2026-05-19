class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(auto it:nums){
            mpp[it]++;
        }
        vector<vector<int>>bucket(n+1);
        for(auto it:mpp){
            int num=it.first;
            int freq=it.second;
            bucket[freq].push_back(num);
        }
        vector<int>ans;
        for(int i=n;i>0;i--){

            for(auto it:bucket[i]){
                
                if(ans.size()<k)ans.push_back(it);
            }
            

        }
        return ans;
    }
};
