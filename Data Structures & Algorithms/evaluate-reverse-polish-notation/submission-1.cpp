class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>s;

        for(auto it:tokens){
            if(it!="+" && it!="-" && it!="*" && it!="/"){
                s.push(stoi(it));
            }
            else{
                int first,sec;
                if(!s.empty()){
                 sec=s.top();
                s.pop();
                }
                if(!s.empty()){
                 first=s.top();
                s.pop();
                }
                if(it=="+")s.push(first+sec);
                else if(it=="-")s.push(first-sec);
                else if(it=="*")s.push(first*sec);
                else if(it=="/")s.push(first/sec);
                

            }
        }
            return s.top();
        
    }
};
