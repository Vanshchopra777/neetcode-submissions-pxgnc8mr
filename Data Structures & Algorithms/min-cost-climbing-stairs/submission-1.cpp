class Solution {
public:
    int solve(int i,vector<int>& cost,int n,vector<int>&t){
        if(i>=n)return 0;
        if(t[i]!=-1)return t[i];

        return t[i]=cost[i]+min(solve(i+1,cost,n,t),solve(i+2,cost,n,t));

        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        vector<int>t(n+1,-1);

        return min(solve(0,cost,n,t),solve(1,cost,n,t));
        
    }
};
