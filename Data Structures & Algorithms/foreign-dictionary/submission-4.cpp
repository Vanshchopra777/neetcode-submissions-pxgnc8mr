class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        int n=words.size();
        vector<vector<int>>adj(26);
        vector<bool>present(26,false);
        vector<int>indegree(26,0);
        for(auto it:words){
            for(auto ch:it){
                present[ch-'a']=true;
            }
        }
        for(int i=0;i<n-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int j;

            int len=min(w1.length(),w2.length());

            for( j=0;j<len;j++){
                

                if(w1[j]!=w2[j]){

                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    indegree[w2[j]-'a']++;
                    break;

                }
                
            }
            if(w1.length()>w2.length() && j==len)return "";

        }

        queue<int>q;
    int count=0;
        for(int i=0;i<26;i++){
            if(present[i])count++;
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }
    string ans="";
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans+=(node+'a');

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.length()!=count)return "";
        return ans;
        
    }
};
