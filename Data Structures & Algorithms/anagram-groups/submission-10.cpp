class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        unordered_map<string,vector<string>>mpp;
        for(auto it:strs){

            vector<int>freq(26,0);

            for(auto ch:it){
                freq[ch-'a']++;
            }
            string key="";

            for(int i=0;i<26;i++){
                key+=freq[i];
                key+='#';
            }
            mpp[key].push_back(it);

        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
