class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});

        }
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        vector<int>time(n+1,1e9);
        time[0]=0;
        time[k]=0;

        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(t>time[node])continue;
            for(auto it:adj[node]){
                int nextnode=it.first;
                int wt=it.second;

                if(time[node]+wt<time[nextnode]){
                    time[nextnode]=time[node]+wt;
                    pq.push({time[nextnode],nextnode});
                }
            }
            
        }
        int  tm=INT_MIN;
        for(auto it:time){
            tm=max(tm,it);

        }
        if(tm==1e9)return -1;

        return tm;
        
    }
};
