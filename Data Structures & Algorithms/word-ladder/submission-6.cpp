class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        int step=1;
        if(st.count(endWord)==0)return 0;

        while(!q.empty()){

            int sz=q.size();
            while(sz--){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return step;
                }

                for(int i=0;i<word.length();i++){
                    char original=word[i];

                    for(char c='a';c<='z';c++){
                        word[i]=c;

                        if(st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i]=original;
                }


            }
            step++;
        }
        return 0;
        
    }
};
