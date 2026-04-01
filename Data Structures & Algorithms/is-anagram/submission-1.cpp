class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>mpp;

        for(auto it:s){
            mpp[it]++;
        }
        for(auto it:t){
            mpp[it]--;
            if(mpp[it]==0)mpp.erase(it);
        }
        if(mpp.size()==0)return true;
        else return false;
        
    }
};
