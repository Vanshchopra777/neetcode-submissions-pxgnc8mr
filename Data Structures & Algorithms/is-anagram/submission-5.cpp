class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;

        unordered_map<int,int>mpp;
        for(auto it:s){
            mpp[it-'a']++;

        }
        int sz=mpp.size();
        for(auto it:t){
            mpp[it-'a']--;
            if(mpp[it-'a']==0){
                sz--;
            }
        }
        return sz==0;
        
    }
};
