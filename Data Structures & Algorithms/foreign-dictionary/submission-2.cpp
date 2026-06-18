class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();

        
        vector<int>present(26,0);
        for(auto it:words){
            for(auto ch:it){
                present[ch-'a']=1;
            }

        }
        int totalchar=0;
        for(auto it :present){
            if(it==1)totalchar++;
        }
        vector<vector<int>>adj(26);

        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.length(),s2.length());
            if(s1.length()>s2.length() && s1.substr(0, len) == s2) return "";

            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }

        vector<int>indegree(26);
        string ans="";
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;

        for(int i=0;i<26;i++){
            if(indegree[i]==0 && present[i])q.push(i);
        }

        while(!q.empty()){

            int node=q.front();
            q.pop();

            ans+=char(node+'a');

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0 && present[it]){
                    q.push(it);
                }
            }

        }
        if(ans.length()!=totalchar) return "";
        
        return ans;


    }
};
