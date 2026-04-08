class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int>last(256,-1);
            int i=0;
            int maxlen=0;
        for(int j=0;j<s.length();j++){

            if(last[s[j]]>=i){
                i=last[s[j]]+1;

            }
            last[s[j]]=j;
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }
};
