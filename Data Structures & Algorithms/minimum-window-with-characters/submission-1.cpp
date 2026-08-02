class Solution {
public:
    string minWindow(string s, string t) {
        int n2=t.length();
        int n1=s.length();
       
       
        if(n2>n1)return "";
       
        unordered_map<char,int>mpp;

        int minlen=INT_MAX;;
        for(auto it:t){
            mpp[it]++;

        }
        int sz=mpp.size();
        int start;
        int i=0;
        int j=0;
        while(j<n1){

             if(mpp.count(s[j])){
                mpp[s[j]]--;
                if(mpp[s[j]]==0)sz--;
            }
            
            while(sz==0){
                if(mpp.count(s[i])){
                    mpp[s[i]]++;
                    if(mpp[s[i]]>0)sz++;

                }
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    start=i;

                }
               
                i++;
            }
            j++;
           
        }
          if(minlen == INT_MAX)
            return "";
        return s.substr(start,minlen);
    }
};
