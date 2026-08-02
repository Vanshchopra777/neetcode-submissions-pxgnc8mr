class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int mxfreq=0;
        int maxlen=0;
        unordered_map<char,int>mpp;
        while(j<n){
            mpp[s[j]]++;
            mxfreq=max(mxfreq,mpp[s[j]]);

            while(j-i+1-mxfreq>k){
                mpp[s[i]]--;
                i++;
            }

            if(j-i+1-mxfreq<=k){
                maxlen=max(maxlen,j-i+1);
            }
            j++;


        }
        return maxlen;
        
    }
};
