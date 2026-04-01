class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int>mpp;
        int start;

        for(auto it:t){
            mpp[it]++;
        }
        int cnt=mpp.size();

        int i=0;
        int j=0;
        int minlen=INT_MAX;
        int n=s.length();
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0)cnt--;
            }

            while(cnt==0){
                if(mpp.find(s[i])!=mpp.end()){
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1){
                        cnt++;

                    if(j-i+1<minlen){
                        minlen=j-i+1;
                        start=i;
                    }
                    }

                }
                i++;
            }
            j++;
        }
          if(minlen==INT_MAX) return "";
        return s.substr(start, minlen);



        
    }
};
