class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int len=0;
        int num;
        int maxlen=0;

        for(auto it:nums){
            if(st.count(it-1))continue;
            len=1;
            num=it;

            while(st.count(num+1)){
                len++;
                num++;
            }
            maxlen=max(maxlen,len);


        }
        return maxlen;
        
        
    }
};
