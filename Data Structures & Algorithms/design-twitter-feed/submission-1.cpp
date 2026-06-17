class Twitter {
public:
    int timestamp=0;
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweet;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        tweet[userId].push_back({tweetId,timestamp});
        timestamp++;

        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;

        priority_queue<vector<int>>pq;
        following[userId].insert(userId);

        for(auto it:following[userId]){
if(tweet[it].empty())
        continue;
            int ind=tweet[it].size()-1;

            pq.push({tweet[it][ind].second,tweet[it][ind].first,it,ind});


        }
        

        while(!pq.empty() && ans.size()<10){
            auto curr=pq.top();
            pq.pop();

            int time=curr[0];
            int tweetid=curr[1];
            int id=curr[2];
            int index=curr[3];
            ans.push_back(tweetid);

            if(index-1>=0){
                pq.push({tweet[id][index-1].second,tweet[id][index-1].first,id,index-1});
            }
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
    }
};
