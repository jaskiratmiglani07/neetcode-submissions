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
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        auto pushLastTen = [&](int uid) {
            auto& tweets = tpu[uid];
            int n = tweets.size();
            for (int i = n - 1; i >= max(0, n - 10); i--) {
                pq.push(tweets[i]);
            }
        };
        pushLastTen(userId);
        for (int followee : fg[userId]) {
            if (followee != userId) {
                pushLastTen(followee);
            }
        }
        int k = 10;
        while (k-- && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
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
