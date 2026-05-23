class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int target = -(nums[i]);
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            // vector<int>ls;
            while(j<k){

               
                
               if(nums[j]+nums[k]==target){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                 while(nums[j]==nums[j-1] && j<k)j++;
                while(nums[k]==nums[k+1] && j<k  )k--;

               }
               
               else if(nums[j]+nums[k]>target)k--;
               else{
                j++;
               }
               

            }
            

        }
        return ans;
    }
};
