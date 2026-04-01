class Solution {
public:
    bool can_eat(vector<int>& piles,int k, int h){
        int hours=0;
        for(auto it:piles){
            hours+=(it+k-1)/k;

        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=*max_element(piles.begin(), piles.end());
    int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(can_eat(piles,mid,h)){
                 ans=mid;
                high=mid-1;

            }
            else low=mid+1;

        }
        return ans;
        
    }
};
