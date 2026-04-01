class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        unordered_map<int,int>mpp;
        int maxlen=0;
        while(j<n){

            mpp[s[j]]++;
            if(mpp.size()<j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            if(mpp.size()==j-i+1){
                maxlen=max(maxlen,j-i+1);
            }
            j++;
        }
        return maxlen;

    }
};
