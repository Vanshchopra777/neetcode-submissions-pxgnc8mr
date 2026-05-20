class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<double>time(n);
        unordered_map<int,double>mpp;
        for(int i=0;i<n;i++){
            time[i]=(double)(target-position[i])/speed[i];
            mpp[position[i]]=time[i];


        }
        sort(position.begin(), position.end(), greater<int>());
        int fleet=0;
        double prevtime=0;
        for(auto it:position){
            
            if(mpp[it]>prevtime)
            {
                fleet++;
            prevtime=mpp[it];

            }

        }
        return fleet;
        
    }
};
