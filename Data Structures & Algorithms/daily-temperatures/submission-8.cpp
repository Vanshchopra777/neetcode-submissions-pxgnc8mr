class Solution {
public:
    void solve(vector<int>&ans,vector<int> nums){

        stack<pair<int,int>>st;
        int n=nums.size();
        

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                ans.push_back(0);

            }

            else if(!st.empty() && st.top().first>nums[i]){
                ans.push_back(st.top().second-i);

            }
            else if(!st.empty() && st.top().first<=nums[i]){
                while(!st.empty() && st.top().first<=nums[i]){
                    st.pop();
                }
                  if(st.empty()){
                ans.push_back(0);

            }

            else if(!st.empty() && st.top().first>nums[i]){
                ans.push_back(st.top().second-i);

            }

            }

            st.push({nums[i],i});

        }
        reverse(ans.begin(),ans.end());
    
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int>ngr;

        solve(ngr,temperatures);
        return ngr;





        
    }
};
