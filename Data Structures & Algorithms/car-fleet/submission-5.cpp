class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>pos_time;
        int n=speed.size();

        for(int i=0;i<n;i++){
            float time=(double)(target-position[i])/(double)speed[i];
            pos_time.push_back({position[i],time});
        }
        sort(pos_time.begin(),pos_time.end());
        stack<double>st;
        int fleet=0;
        
        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                fleet=1;
                 st.push(pos_time[i].second);
            }
            else if(pos_time[i].second>st.top()){
                fleet++;
                 st.push(pos_time[i].second);

            }
           

        }
        return fleet;
        

    }
};
