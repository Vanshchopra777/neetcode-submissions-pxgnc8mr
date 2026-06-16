class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;

        for(auto it:tasks){
            mpp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mpp){
            pq.push(it.second);

        }
        int totaltime=0;
       
        while(!pq.empty()){
             int available_slot=n+1;
            int task_executed=0;
            vector<int>remain;

            while(available_slot>0 && !pq.empty()){
                int freq=pq.top();
                pq.pop();
                task_executed++;
                freq--;

                if(freq>0){
                    remain.push_back(freq);
                }
               
               available_slot--;

            }
             for(auto it:remain){
                    pq.push(it);
                }

        if(!pq.empty())totaltime+=n+1;
        else{
            totaltime+=task_executed;
        }


        }
        return totaltime;
      

    }
};
