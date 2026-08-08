class MinStack {
public:
    long long minele;
    stack<long long>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minele=val;
        }
        else{
            if(val<minele){
                st.push(2LL*val-minele);
                minele=val;
            }
            else st.push(val);
        }

        
    }
    
    void pop() {

        if(st.top()<minele){
            minele=2*minele-st.top();
            st.pop();


        }
        else st.pop();
        
    }
    
    int top() {

        if(st.top()<minele){
            return minele;
        }
        return st.top();
        
    }
    
    int getMin() {
        return minele;
        
    }
};
