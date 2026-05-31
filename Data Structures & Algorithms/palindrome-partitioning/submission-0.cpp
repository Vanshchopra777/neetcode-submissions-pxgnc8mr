class Solution {
public:

    bool ispalindrome(string st){
        int i=0;
        int j=st.length()-1;
        while(i<=j){
            if(st[i]!=st[j])return false;

            i++;
            j--;
        }
        
        return true;
    }

    void solve(string s,int start,vector<string>&temp,vector<vector<string>>&ans){
        int n=s.length();
        if(start==n){
            ans.push_back(temp);
            return ;
        }
        string st="";
        for(int i=start;i<n;i++){
            st+=s[i];
            if(ispalindrome(st)){
                temp.push_back(st);
                solve(s,i+1,temp,ans);
                temp.pop_back();
            }

        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;

        
    }
};
