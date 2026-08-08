class Solution {
public:
    bool caneat(int k,vector<int>& piles, int h){
        int time=0;

        for(auto it:piles){
            time+=(it+k-1)/k;

        }
        if(time<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        if(h<n)return -1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(caneat(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};
