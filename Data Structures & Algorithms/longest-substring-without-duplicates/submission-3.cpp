class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int n=s.length();
        int i=0;
        int j=0;
        int maxlen=0;

        while(j<n){
            freq[s[j]]++;
            while(freq[s[j]]>1){
                freq[s[i]]--;
                i++;
            }

            maxlen=max(maxlen,j-i+1);
            j++;

        }
        return maxlen;
        
    }
};
