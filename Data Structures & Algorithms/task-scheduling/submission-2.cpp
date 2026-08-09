class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<int,int>mpp;
        priority_queue<int>pq;

        for(auto it:tasks){
            mpp[it-'A']++;
        }

        for(auto it:mpp){
            pq.push(it.second);
        }

        int totaltime=0;

        while(!pq.empty()){
            int taskexecuted=0;
            int cycle=n+1;
            vector<int>temp;

            while(cycle && !pq.empty()){
            int remaining=pq.top();
            pq.pop();
            taskexecuted++;
            remaining--;
            cycle--;

            if(remaining)temp.push_back(remaining);


            }

            for(auto it:temp){
                pq.push(it);
            }

            if(!pq.empty())totaltime+=n+1;
            else totaltime+=taskexecuted;


        }
        return totaltime;

        
    }
};
