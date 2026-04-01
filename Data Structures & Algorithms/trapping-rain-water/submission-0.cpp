class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftmax(n);
        leftmax[0]=0;
        vector<int>rightmax(n);
        rightmax[n-1]=nums[n-1];

        for(int i=0;i<n;i++){
            leftmax[i]=max(leftmax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],nums[i]);
        }
        
        int area=0;
        for(int i=0;i<n;i++){
            area+=min(leftmax[i],rightmax[i])-nums[i];

        }
        return area;

        
    }
};
