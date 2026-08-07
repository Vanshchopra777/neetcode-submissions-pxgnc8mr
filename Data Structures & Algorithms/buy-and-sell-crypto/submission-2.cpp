class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int prevmin=prices[0];
        int maxprofit=0;

        for(auto it:prices){

            maxprofit=max(maxprofit,it-prevmin);
            prevmin=min(prevmin,it);
            


        }
        return maxprofit;




        
    }
};
