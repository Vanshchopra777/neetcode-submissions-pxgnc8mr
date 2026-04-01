class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>mpp(nums.begin(),nums.end());
        int maxlen=0;
        int len=0;
        // for(auto it:nums)mpp[it]++;

        for(auto it:nums){
            
            if(mpp.find(it-1)!=mpp.end())continue;
            else{
                len=1;
                int el=it+1;
                while(mpp.find(el)!=mpp.end()){
                    len++;
                    
                    el++;
                }

                maxlen=max(maxlen,len);
            }
            

        }
        return maxlen;
        
    }
};
