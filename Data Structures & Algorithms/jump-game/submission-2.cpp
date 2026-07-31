class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxidx=0;
        for(int i=0;i<n;i++){
            if(maxidx>=n-1)return true;
            if(i>maxidx)return false;
            maxidx=max(i+nums[i],maxidx);
            


        }
        return true;
        
    }
};
