class Solution {
public:
    int solve(vector<int>& nums,int target,int newsum,vector<vector<int>>&t,int n){

        for(int i=0;i<n+1;i++){
            for(int j=0;j<newsum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
         for(int i=1;i<n+1;i++){
            for(int j=1;j<newsum+1;j++){
                
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                }
                else{
                   t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][newsum];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // p1+p2=sum
        // p1-p2=target
        // p1=sum+target/2;
        int n=nums.size();
        int sum=0;
        int zero=0;
        vector<int>newnums;
        for(auto it:nums){
            sum+=it;
            if(it!=0)newnums.push_back(it);
            else {
                zero++;
            }

        }
        if(abs(target) > sum)
    return 0;
        if((sum+target)%2!=0)return 0;

        
        
        int newsum=(sum+target)/2;
        
        int newn=newnums.size();
        vector<vector<int>>t(newn+1,vector<int>(newsum+1,0));
        return pow(2,zero)*solve(newnums,target,newsum,t,newn);

        
    }
};
