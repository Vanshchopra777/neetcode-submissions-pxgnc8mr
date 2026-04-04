class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        if(beginWord==endWord)return 1;

        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();

            int len=word.length();
             if(word==endWord)return step;
            for(int i=0;i<len;i++){
                char  original=word[i];
                for(char c='a';c<='z';c++){
                    if(c==original)continue;
                    

                    word[i]=c;
                   
                    
                    if(st.find(word)!=st.end()){
                        if(word==endWord)return step+1;
                        q.push({word,step+1});
                        st.erase(word);

                    }
                }
                word[i]=original;
            }
        }
        return 0;

        
    }
};
