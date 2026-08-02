class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        int start=0;
        int maxlen=0;


        for(int i=0;i<n;i++){
            if(mpp.count(s[i]) && mpp[s[i]]>=start){
                start=mpp[s[i]]+1;
                

            }

            mpp[s[i]]=i;
            maxlen=max(maxlen,i-start+1);


        }
        return maxlen;
        
    }
};
