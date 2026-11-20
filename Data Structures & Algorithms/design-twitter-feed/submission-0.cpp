class Twitter {
public:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>>tpu;//userid -> {timestamp, tweetId}
    unordered_map<int, unordered_set<int>>fg;//follower_id -> followee_id(unique)
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tpu[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<pair<int, int>>pq;
        int k = 10;
        for(auto x : tpu[userId]){
            pq.push(x);
        }
        for(auto x : fg[userId]){//everyone they follow
            if(x != userId){
                for(auto y : tpu[x]){
                    pq.push(y);
                }
            }
        }
        while(!pq.empty() && k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        fg[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fg[followerId].erase(followeeId);
    }
};
