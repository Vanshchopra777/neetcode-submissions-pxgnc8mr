class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
         vector<int> present(26, 0);

        // mark present characters
        for(auto &word : words) {
            for(char c : word) {
                present[c - 'a'] = 1;
            }
        }

        vector<vector<int>>adj(26);
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.length(),s2.length());
            if(s1.size() > s2.size() && s1.substr(0, len) == s2) {
    return "";
}

            
            for(int i=0;i<len;i++){
                if(s1[i]!=s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        vector<int>indeg(26,0);
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                indeg[it]++;

            }
        }
        queue<int>q;
        string topo="";

        for(int i=0;i<26;i++){
            if(indeg[i]==0 && present[i])q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo+=char(node+'a');

            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }

        }
 if(topo.size() < count(present.begin(), present.end(), 1)) {
            return "";
        }
        return topo;
    }
};
