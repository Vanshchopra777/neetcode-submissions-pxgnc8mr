class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();

        stack<pair<int,int>>st;
        vector<int>temp;

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                temp.push_back(i);
            }
            else if(!st.empty() && st.top().first>nums[i]){
                temp.push_back(st.top().second);
            }
            else if(!st.empty() && st.top().first<=nums[i]){
                while(!st.empty() && st.top().first<=nums[i]){
                    st.pop();

                }
                 if(st.empty()){
                temp.push_back(i);
            }
            else if(!st.empty() && st.top().first>nums[i]){
                temp.push_back(st.top().second);
            }

            }
            st.push({nums[i],i});

        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            temp[i]=temp[i]-i;
        }
        return temp;
    }
};
