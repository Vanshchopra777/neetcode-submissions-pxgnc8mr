class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();

        stack<pair<int,int>>st;
        vector<int>temp;

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                temp.push_back(0);
            }
            else if(!st.empty() && st.top().first>nums[i]){
                temp.push_back(st.top().second-i);
            }
            else if(!st.empty() && st.top().first<=nums[i]){
                while(!st.empty() && st.top().first<=nums[i]){
                    st.pop();

                }
                 if(st.empty()){
                temp.push_back(0);
            }
            else if(!st.empty() && st.top().first>nums[i]){
                temp.push_back(st.top().second-i);
            }

            }
            st.push({nums[i],i});

        }
        reverse(temp.begin(),temp.end());
        
        return temp;
    }
};
