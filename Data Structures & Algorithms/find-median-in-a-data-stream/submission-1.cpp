class MedianFinder {
public:
    priority_queue<int>leftmax;
    priority_queue<int,vector<int>,greater<int>>rightmin;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftmax.empty() || num<=leftmax.top()){
            leftmax.push(num);

        }
        else rightmin.push(num);

        if(leftmax.size()>rightmin.size()+1){
            rightmin.push(leftmax.top());
            leftmax.pop();
        }
        else if(rightmin.size()>leftmax.size()){
            leftmax.push(rightmin.top());
            rightmin.pop();
        }
        
    }
    
    double findMedian() {
        int n1=leftmax.size();
        int n2=rightmin.size();

        if(n1>n2)return (double)leftmax.top();

        return (double)(leftmax.top()+rightmin.top())/2.0;
        
    }
};
