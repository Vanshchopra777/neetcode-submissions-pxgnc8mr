class Solution {
public:
    bool ismatch(char b,char a){
        if(a=='[' && b==']') return true;
        else if(a=='{' && b=='}')return true;
        else if(a=='(' && b==')')return true;

        else return false ;
    }
    bool isValid(string s) {

        stack<char>st;
        for(auto it:s){
            if(it=='(' ||it=='{' || it=='['){
                st.push(it);
                continue;
            }
            else{
                if(st.empty())return false;
                if (ismatch(it,st.top())){
                    st.pop();
                     }
                else return false;
            }

        }
        if(st.empty())return true;
        else return false;
        
    }
};
