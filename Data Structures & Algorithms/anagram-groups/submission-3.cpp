class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(auto it:strs){
            vector<int>freq(26,0);
            for(auto c:it){
                 freq[c-'a']++;
               
            }

                string key="";
                for(int i=0;i<26;i++){
                key+=to_string(freq[i])+"#";
                }
                mpp[key].push_back(it);
            
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);

        }
        return ans;
        
    }
};
