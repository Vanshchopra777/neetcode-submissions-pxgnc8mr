class MinStack {
public:
    long long minele;
    stack<long long>s;
    MinStack() {
        
    }
    
    void push(long long val) {

        if(s.empty()){
            s.push(val);
            minele=val;

        }
        else{

            if(val>=minele)s.push(val);
            else{
                s.push(2*val-minele);
                minele=val;
            }
        }

        
    }
    
    void pop() {
        // if(s.empty())return -1;
        {

            if(s.top()>=minele)s.pop();
            else{
                minele=2*minele-s.top();
                s.pop();
            }
        }
        
    }
    
    long long top() {
        
        if(s.empty())return -1;

        if(s.top()>=minele)return s.top();
        else{
            return minele;
        }
    }
    
    long long getMin() {
        if(s.empty())return -1;

        return minele;
        
    }
};
