class Solution {
public:
    pair<int,int> expand(int l,int r,string &s){
        int len=0;
        while(l<=r){
            if(l >= 0 && r < s.size() && s[l] == s[r]){
                len=r-l+1;
                l--;
                r++;
            }
            else break;
        }
        return {l+1,len};


    }
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1 ||n==0)return s;
        int maxlen=0;
        string ans="";

       for(int i=0;i<n;i++){

        pair<int,int>odd=expand(i,i,s);
        if(odd.second>maxlen){
            maxlen=odd.second;
            ans=s.substr(odd.first,odd.second);
        }
        pair<int,int>even=expand(i,i+1,s);
        if(even.second>maxlen){
            maxlen=even.second;
            ans=s.substr(even.first,even.second);
        }
        


       }
       return ans;

    }
};
