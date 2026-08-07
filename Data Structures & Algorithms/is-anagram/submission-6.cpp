class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length();
        vector<int>freq(26,0);
        
        
        for(auto it:s){
            freq[it-'a']++;

        }
        for(auto it:t){
            freq[it-'a']--;
        }
        for(auto it:freq){
            if(it!=0)return false;
        }
        return true;
    }
};
