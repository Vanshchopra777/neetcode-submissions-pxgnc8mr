class MinStack {
public:
    stack<long long>st;
    long long minele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
             st.push(val);
            minele = val;


        }
        else if(val>=minele){
            st.push(val);
        
        }
        else{
            st.push(2LL*val-minele);
            minele=val;
        }
        
    }
    
    void pop() {
        if(st.top()>=minele)st.pop();
        else{
            minele=2LL *minele-st.top();
            st.pop();
        }
        
    }
    
    int top() {
        if(st.top()<minele)return minele;

        return st.top();
        
    }
    
    int getMin() {
        return minele;
        
    }
};
