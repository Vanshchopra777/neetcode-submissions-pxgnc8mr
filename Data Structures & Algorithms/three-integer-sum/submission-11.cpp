class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
       
         set<vector<int>> st;
        for(int i=0;i<n;i++){
            // if(i>0 && nums[i]==nums[i-1])continue;
            int target=-1*nums[i];
            unordered_map<int,int>mpp;

            for(int j=i+1;j<n;j++){
                if(mpp.count(target-nums[j])){
                    vector<int>temp={nums[i],target-nums[j],nums[j]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }

                mpp[nums[j]]=j;

            }

        }
        return vector<vector<int>>(st.begin(),st.end());
        
    }
};
