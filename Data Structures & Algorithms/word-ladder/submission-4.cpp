class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


        unordered_set<string>st(wordList.begin(),wordList.end());

        if(st.find(endWord)==st.end())return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){

            int step=q.front().second;
            string word=q.front().first;
            if(word==endWord) return step;
            q.pop();
            int len=word.length();
            for(int i=0;i<len;i++){
                char original=word[i];

                for(char ch='a';ch<='z';ch++){
                    if(ch==word[i])continue;
                    word[i]=ch;

                    if(st.find(word)!=st.end()){
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
