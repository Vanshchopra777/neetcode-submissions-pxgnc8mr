class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int>mpp;

        for(auto it:s1){
            mpp[it-'a']++;

        }
         int cnt=mpp.size();
        int i=0;
        int j=0;
        int l1=s1.length();
        int l2=s2.length();
       
        while(j<l2){
            if(mpp.find(s2[j]-'a')!=mpp.end()){
                mpp[s2[j]-'a']--;
                if(mpp[s2[j]-'a']==0)cnt--;
            }
            while(j-i+1>l1){
               if(mpp.find(s2[i]-'a')!=mpp.end()){

                mpp[s2[i]-'a']++;
                if(mpp[s2[i]-'a']==1)cnt++;
                
               }
                i++;

            }
            if(j-i+1==l1){
               if(cnt==0)return true;

            }

            j++;
        }
        return false;


        
    }
};
