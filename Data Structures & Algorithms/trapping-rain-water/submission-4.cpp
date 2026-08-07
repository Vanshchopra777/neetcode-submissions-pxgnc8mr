class Solution {
public:
    int trap(vector<int>& nums) {

        int leftmax=0;
        int rightmax=0;
        int n=nums.size();

        int i=0;
        int j=n-1;
        int water=0;
        

        while(i<j){
            if(nums[i]<=nums[j]){
                if(nums[i]>=leftmax){
                    leftmax=nums[i];
                }
                else water+=leftmax-nums[i];

                i++;
            }
            else{
                 if(nums[j]>=rightmax){
                    rightmax=nums[j];
                }
                else water+=rightmax-nums[j];

                j--;
                
            }

        }
        return water;
        
    }
};
