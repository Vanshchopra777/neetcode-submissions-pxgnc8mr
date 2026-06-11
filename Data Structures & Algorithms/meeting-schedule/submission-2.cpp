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
        return a.end < b.end ;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {

        int n=intervals.size();
        if(n==0)return true;
        sort(intervals.begin(),intervals.end(),comp);

        int freelast=intervals[0].end;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(intervals[i].start >= freelast){
                cnt++;
                freelast=intervals[i].end;
            }


        }
        if(cnt==n)return true;

        return false;
        
    }
};
