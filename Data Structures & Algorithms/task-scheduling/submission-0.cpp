class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;

        for(char it:tasks){
            mpp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mpp){
            pq.push(it.second);
        }
        queue<pair<int,int>>q;

        int time=0;
        while(!pq.empty() || !q.empty()){
           time++;
           
            if(!pq.empty()){
                
                int cnt=pq.top();
                pq.pop();
                cnt--;

                if(cnt>0)q.push({cnt,time+n});


            }
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
            return time;

        
    }
};

// pq max heap me freq 
// time++ , cnt-- put in queue {cnt,time}

// if(time==relaxtime)put cnt back into pq
