class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ngr;
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty())ngr.push_back(i);

            else if(st.size()>0 && st.top().first>temperatures[i]){
                ngr.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first<=temperatures[i]){
                while(st.size()>0 && st.top().first<=temperatures[i]){
                    st.pop();

                }
                if(st.empty())ngr.push_back(i);

            else if(st.size()>0 && st.top().first>temperatures[i]){
                ngr.push_back(st.top().second);
                }

            }
            st.push({temperatures[i],i});

        }
        reverse(ngr.begin(),ngr.end());
        vector<int>ans;
        int i=0;
        for(auto it:ngr){
            
            ans.push_back(it-i);
            i++;

        }
        return ans;

        
    }
};
