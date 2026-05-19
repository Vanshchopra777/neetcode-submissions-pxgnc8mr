class Solution {
public:

    string encode(vector<string>& strs) {
        string cipher="";
        for(auto it:strs){
            int n=it.length();
            
            cipher+=to_string(n);
            cipher+='#';
            cipher+=it;
        }
        return cipher;

    }

    vector<string> decode(string s) {
        int n=s.length();
         if(n==0)return {};
        vector<string>ans;
        
       
        int i=0;
        while(i<n){
            string sizeofstr="";
            while(s[i]!='#'){
                sizeofstr+=s[i];
                i++;
            }
            int len=stoi(sizeofstr);
            i++;

            ans.push_back(s.substr(i,len));
            i+=len;


        }
        return ans;

    }
};
