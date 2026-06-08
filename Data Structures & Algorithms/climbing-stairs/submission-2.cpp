class Solution {
public:

    int solve(int n,int i,vector<int>&t){
        
        for(int i=n-2;i>=0;i--){

        //     if(i==n){
        //         t[i]=1;
           
        // }
        // if(i>n) t[i]=0;
        t[i]=t[i+1]+t[i+2];

        }
        return t[0];
        
        
        

    }
    int climbStairs(int n) {
        vector<int>t(n+1,0);
        t[n]=1;
        t[n-1]=1;
        return solve(n,0,t);
        
    }
};
