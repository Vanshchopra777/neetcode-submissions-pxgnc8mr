class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<int,int>mpp;

        int i=0;
        int j=0;
        int n=s.length();
        int maxlen=0;


        while(j<n){

            mpp[s[j]]++;

            while(j-i+1>mpp.size()){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);

                i++;

            }
            maxlen=max(maxlen,j-i+1);

            j++;

        }
        return maxlen;

        
    }
};
