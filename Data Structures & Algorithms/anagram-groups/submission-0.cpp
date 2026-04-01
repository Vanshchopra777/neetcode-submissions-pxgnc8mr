class Solution {
public:
    // bool isanagram(string &a,string &b){
    //     if(a.length()!=b.length())return false;

    //     unordered_map<char,int>mpp;
    //     for(auto it:a){
    //         mpp[it]++;
    //     }
    //     for(auto it:b){
    //         mpp[it]--;
    //         if(mpp[it]==0)mpp.erase(it);
    //     }
    //     if(mpp.size()==0)return true;
    //     else return false;



    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string, vector<string>> mpp;

        for(auto it:strs){
            string key=it;
            sort(key.begin(),key.end());
            mpp[key].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
