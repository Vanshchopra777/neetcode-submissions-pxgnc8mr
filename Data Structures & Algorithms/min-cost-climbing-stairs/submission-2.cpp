class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>t(n+2,0);
        for(int i=n-1;i>=0;i--){

            t[i]=cost[i]+min(t[i+1],t[i+2]);


        }
        return min(t[0],t[1]);
        
    }
};
