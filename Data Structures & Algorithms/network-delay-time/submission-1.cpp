class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>time_arr(n+1,1e9);
        time_arr[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;

                if(time+wt<time_arr[adjnode]){
                    time_arr[adjnode]=time+wt;
                    pq.push({time_arr[adjnode],adjnode});
                }
            }

        }
        int tmin=INT_MIN;
        time_arr[0]=0;

        for(auto it:time_arr){
            if(it==1e9) return -1;
            
            tmin=max(tmin,it);
        }
        return tmin;
    }
};
