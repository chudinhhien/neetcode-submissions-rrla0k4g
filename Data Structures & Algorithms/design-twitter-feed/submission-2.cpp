class Twitter {
private:
    int time;

    int mostRecentTweet;

    unordered_map<int, unordered_set<int>> followees;

    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
        time = 0;
        mostRecentTweet = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;

        unordered_set<int> targets = followees[userId];

        targets.insert(userId);

        for(int targetId : targets) {
            for(int i = 0 ; i < tweets[targetId].size(); i++) {
                pq.push(tweets[targetId][i]);
                if(pq.size() > mostRecentTweet) pq.pop();
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
