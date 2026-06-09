class Solution {
public:
    bool solve(int sum,vector<int>&nums,vector<vector<int>>&t,int n){

        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0)t[i][j]=true;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
               
               if(nums[i-1]<=j){
                t[i][j]=(t[i-1][j] || t[i-1][j-nums[i-1]]);

               }
               else{
                t[i][j]=t[i-1][j] ;
               }

            }
            
        }
        
    return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;

        for(auto it:nums){
            sum+=it;

        }
        
        if(sum%2!=0)return false;
        int n=nums.size();
        int newsum=sum/2;
        vector<vector<int>>t(n+1,vector<int>(newsum+1,false));
        
        return solve(newsum,nums,t,n);
    }
};
