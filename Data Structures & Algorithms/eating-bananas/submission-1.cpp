class Solution {
public:

    bool can_eat(vector<int>& piles,int rate, int h){

        int timereq=0;
        for(auto it:piles){
            timereq+=(it+rate-1)/rate ;
        }
        if(timereq<=h)return true;
        
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {


        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid =(low+high)/2;
            

            if(can_eat(piles,mid,h)){
                ans=mid;
                high=mid-1;


            }
            else{
                low=mid+1;
            }

        }
        return ans;

        
    }
};
