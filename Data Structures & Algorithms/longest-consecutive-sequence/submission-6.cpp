class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        unordered_set<int>mpp(nums.begin(),nums.end());
        
        int longest=1;
        for(auto it:nums){
            if(mpp.find(it-1)!=mpp.end())continue;
            int len=1;
            int el=it+1;
            while(mpp.find(el)!=mpp.end()){
                len++;
                
                el++;

            }
            longest=max(longest,len);
        }
        return longest;
    }
};
