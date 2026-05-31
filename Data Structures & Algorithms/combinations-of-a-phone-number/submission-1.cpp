class Solution {
public:

    void solve(string digits,string &temp,int index,unordered_map<char,string>&mpp, vector<string>&ans){
        

        if(index==digits.length()){
            ans.push_back(temp);
            return;
        }

        for(auto ch:mpp[digits[index]]){
            temp+=ch;
            solve(digits,temp,index+1,mpp,ans);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
         if(digits.empty())
            return {};
        unordered_map<char,string>mpp;

        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        vector<string>ans;
        string temp="";

        solve(digits,temp,0,mpp,ans);
       
        return ans;

        
    }
};
