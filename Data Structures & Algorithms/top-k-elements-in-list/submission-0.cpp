class Solution {
public:
static bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second > b.second;  // descending by value
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }

    return ans;

    }
};
