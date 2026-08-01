class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        unordered_map<int,int>mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        sort(hand.begin(),hand.end());
        for(auto it:hand){
            if(mpp[it]==0)continue;

            for(int i=0;i<groupSize;i++){
                if(mpp[i+it]==0)return false;

                mpp[it+i]--;

            }


       
        }
        return true;

        
    }
};
