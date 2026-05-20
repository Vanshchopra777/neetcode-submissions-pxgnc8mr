class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ngr;
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty())ngr.push_back(0);

            else if(st.size()>0 && st.top().first>temperatures[i]){
                ngr.push_back(st.top().second-i);
            }
            else if(st.size()>0 && st.top().first<=temperatures[i]){
                while(st.size()>0 && st.top().first<=temperatures[i]){
                    st.pop();

                }
                if(st.empty())ngr.push_back(0);

            else if(st.size()>0 && st.top().first>temperatures[i]){
                ngr.push_back(st.top().second-i);
                }

            }
            st.push({temperatures[i],i});

        }
        reverse(ngr.begin(),ngr.end());
        
        return ngr;

        
    }
};
