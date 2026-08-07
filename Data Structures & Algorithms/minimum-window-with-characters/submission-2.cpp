class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int>mpp;
        int n=s.length();

        for(auto it:t){
            mpp[it]++;

        }

        int sz=mpp.size();

        int i=0;
        int j=0;
        int minlen=INT_MAX;
        int start=0;
        while(j<n){

              if(mpp.count(s[j])){
                mpp[s[j]]--;
                if(mpp[s[j]]==0)sz--;
            }
            

            while(sz==0){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    start=i;
                }
                
                if(mpp.count(s[i])){
                    mpp[s[i]]++;
                    if(mpp[s[i]]>0)sz++;

                }
                
                i++;
            }
            // minlen=min(minlen,j-i+1);

          
            j++;
        }

        if(minlen==INT_MAX)return "";
        return s.substr(start,minlen);

        
    }
};
