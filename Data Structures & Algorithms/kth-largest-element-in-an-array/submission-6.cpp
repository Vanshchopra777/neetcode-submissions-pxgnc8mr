class Solution {
public:
    int partition(vector<int>& nums,int low,int high){
        int pivot=nums[high];

        int i=low;
        for(int j=low;j<high;j++){
            if(nums[j]<pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[high]);

        return i;
    }
    int quickselect(vector<int>& nums,int low,int high,int target){

        int pivot=partition(nums,low,high);

        if(pivot==target)return nums[pivot];

        if(pivot<target){
           return quickselect(nums,pivot+1,high,target);

        }
        return quickselect(nums,low,pivot-1,target);
    }
    int findKthLargest(vector<int>& nums, int k) {

        int n=nums.size();

        return quickselect(nums,0,n-1,n-k);
        
    }
};
