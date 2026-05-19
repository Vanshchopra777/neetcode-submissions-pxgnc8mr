class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        if(l1!=l2)return false;

        unordered_map<int,int>mpp;
        for(auto it:s){
            mpp[it-'a']++;

        }
        int size_t=mpp.size();

        for(auto it:t){
            mpp[it-'a']--;
            if(mpp[it-'a']==0)size_t--;
        }
        if(size_t==0)return true;
        return false;
    }
};
