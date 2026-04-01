class Solution {
public:
    bool isPalindrome(string s) {

        string temp="";
        for(auto it:s){
            if(isalnum(it)) temp+=tolower(it);
            else continue;
        }
        string rev=temp;
        reverse(rev.begin(),rev.end());
        if(temp==rev)return true;
        else return false;
        
    }
};
