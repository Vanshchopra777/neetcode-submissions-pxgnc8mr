class Solution {
public:
    void solve(int l,int r,string temp,vector<string>&ans){
       if(l==0 && r==0){
        ans.push_back(temp);
        return;
       }
        

       if(l>0)solve(l-1,r,temp+'(',ans);

       if(r>l){
        solve(l,r-1,temp+')',ans);
       }




    }
    vector<string> generateParenthesis(int n) {

        vector<string>ans;
        int left=n;
        int right=n;
        string temp="";
        solve(left,right,temp,ans);
        return ans;
        
    }
};
