/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
      static bool comp(Interval a,Interval b){
        return a.start < b.start ;
    }
    int minMeetingRooms(vector<Interval>& intervals) {

        int n=intervals.size();
        if(n == 0) return 0;
        priority_queue<int,vector<int>,greater<int>>pq;

        sort(intervals.begin(),intervals.end(),comp);
        pq.push(intervals[0].end);
        int room=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(!pq.empty() && intervals[i].start>= pq.top()){
                 pq.pop();
                  room--;
                
            }
        
            pq.push(intervals[i].end);
            room++;
            ans = max(ans, room);


        }
        return ans;

    }
};
