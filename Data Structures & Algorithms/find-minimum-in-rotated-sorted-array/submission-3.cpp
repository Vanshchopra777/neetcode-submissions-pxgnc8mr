class Solution {
public:
    int findMin(vector<int> &nums) {

        int ans=nums[0];
        int low=0;
        int n=nums.size();
        int high=n-1;
        int minans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[low]<=nums[mid]){
                ans=nums[low];
                minans=min(minans,ans);

                low=mid+1;

            }
            else{
                ans=nums[mid];
                minans=min(minans,ans);
                high=mid-1;
            }
        }
        return minans;


        
    }
};
