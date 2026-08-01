class Solution {
public:
    int trap(vector<int>& nums) {

        int n=nums.size();
        int water=0;

        int l=0;
        int r=n-1;

        int leftmax=0;
        int rightmax=0;

        while(l<r){
            if(nums[l]<=nums[r]){

                if(nums[l]>=leftmax){
                    leftmax=nums[l];
                }
                else water+=leftmax-nums[l];

                l++;

            }
            else{

                if(nums[r]>=rightmax){
                    rightmax=nums[r];
                }
                else water+=rightmax-nums[r];

                r--;

            }
        }
        return water;

        
    }
};
