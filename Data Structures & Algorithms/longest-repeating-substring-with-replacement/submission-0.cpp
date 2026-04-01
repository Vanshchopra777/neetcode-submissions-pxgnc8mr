class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[s[j]-'A']++;
            maxfreq=max(maxfreq,mpp[s[j]-'A']);
            while((j-i+1)-maxfreq>k){
                mpp[s[i]-'A']--;
                i++;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,mpp[i]);
                }

            }

            if((j-i+1)-maxfreq<=k){
                maxlen=max(maxlen,j-i+1);
            }


        j++;

        }
        return maxlen;
    }
};
