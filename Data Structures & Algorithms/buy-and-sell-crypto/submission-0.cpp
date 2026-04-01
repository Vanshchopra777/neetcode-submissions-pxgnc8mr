class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       int min_buy=INT_MAX;
       int profit=0;
       for(int i=1;i<n;i++){
        min_buy=min(min_buy,prices[i-1]);
        profit=max(profit,prices[i]-min_buy);
       }
        return profit;
    }
};
