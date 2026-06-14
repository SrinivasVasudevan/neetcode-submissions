class Twitter {
public:
    struct Tweet{
        int id;
        int time;
    };

    struct User{
        int id;
        set<int> followers;
        vector<Tweet> tweets;
    };

    int time;
    unordered_map<int, User> users;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        auto& tweets = users[userId].tweets;
        tweets.push_back({tweetId, time});
        time++;
    }
    


    vector<int> getNewsFeed(int userId) {
        users[userId].followers.insert(userId);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> feed;
        for(auto fId: users[userId].followers){
            auto& tweets = users[fId].tweets;
            insertFeed(tweets, feed);
        }
        vector<int> sol;
        while(feed.size()>0){
            auto [time, tweet] = feed.top();
            feed.pop();
            sol.push_back(tweet);
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }

    void insertFeed(vector<Tweet> tweets, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>& feed){
        for(auto t: tweets){
            int id = t.id;
            int time = t.time;
            if(feed.size()<10){
                feed.push(make_pair(time, id));
            }else{
                auto [topTime, topId] = feed.top();
                if(time > topTime){
                    feed.pop();
                    feed.push(make_pair(time, id));
                }
            }
        }
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].followers.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        users[followerId].followers.erase(followeeId);
    }
};
