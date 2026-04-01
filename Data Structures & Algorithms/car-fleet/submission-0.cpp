class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,double>>ls;
        int n=position.size();

        for(int i=0;i<n;i++){
            double time=double(target-position[i])/speed[i];
            ls.push_back({position[i],time});

        }
        sort(ls.rbegin(),ls.rend());
          double prevtime=0;
            int fleet=0;
        for(auto it:ls){
        
           double curr_time=it.second;
            if(curr_time>prevtime){
                fleet++;
                prevtime =curr_time;

            }

        }
        return fleet;
    }
};
