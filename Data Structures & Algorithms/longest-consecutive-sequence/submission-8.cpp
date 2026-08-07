class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>mpp(nums.begin(),nums.end());
        int maxlen=0;

        for(auto it:nums){
            if(mpp.count(it-1))continue;

            int len=1;
            int num=it;

            while(mpp.count(num+1)){

                len++;
                num++;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};
