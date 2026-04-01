class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<pair<int,int>>st;


        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=0;
            }
            else if(!st.empty() && nums[i]<st.top().first){
                ans[i]=st.top().second-i;
            }
            else if(!st.empty() && nums[i]>=st.top().first){
                while(!st.empty() && nums[i]>=st.top().first){
                    st.pop();
                }
                if(st.empty())ans[i]=0;
                else  ans[i]=st.top().second-i;
            }
            st.push({nums[i],i});
        }
        return ans;

        
    }
};
