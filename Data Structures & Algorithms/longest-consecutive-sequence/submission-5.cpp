class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int longest=1;
        for(auto it:nums){
            if(mpp.find(it-1)!=mpp.end())continue;
            int len=1;
            int el=it+1;
            while(mpp.find(el)!=mpp.end()){
                len++;
                longest=max(len,longest);
                el++;

            }
        }
        return longest;
    }
};
