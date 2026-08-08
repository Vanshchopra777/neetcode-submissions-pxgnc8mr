class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mpp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        

        if(mpp.count(key)==0)return"";
        string ans="";
        vector<pair<int,string>>&temp=mpp[key];

        int low=0;
        int high=temp.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(temp[mid].first<=timestamp){
                ans=temp[mid].second;
                low=mid+1;
            }
            else high=mid-1;


        }
        return ans;


        
        
    }
};
