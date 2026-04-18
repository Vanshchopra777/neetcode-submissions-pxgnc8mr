class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>mpp;

        for(auto it:s){
            mpp[it]++;
        }
        int cnt=mpp.size();
        for(auto it:t){
            mpp[it]--;
            if(mpp[it]==0)cnt--;
        }
        if(cnt==0)return true;
        else return false;
        
    }
};
