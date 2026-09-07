class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int len=0;
        int maxlen=0;
        for(auto it:st){
            if(st.count(it-1))continue;

            len=1;
            int x=it;
            while(st.count(x+1)){
                len++;
                x++;
            }
            maxlen=max(maxlen,len);

        }
        return maxlen;
        
    }
};
