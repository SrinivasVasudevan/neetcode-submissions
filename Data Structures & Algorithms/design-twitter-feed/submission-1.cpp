class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> posts; 
    int time;
    unordered_map<int,unordered_map<int,int>> follower;
    Twitter() {
        time=0;
    }

    
    
    void postTweet(int userId, int tweetId) {
        time++;
        if(posts.find(userId)==posts.end()) posts[userId]=vector<pair<int,int>>();
        posts[userId].push_back(make_pair(time, tweetId));
        follower[userId][userId]=1;
    }
    
    vector<int> getNewsFeed(int userId) {
        struct CompareGreat{
            bool operator()(pair<int,pair<int,int>> l, pair<int,pair<int,int>> r) { return l.first < r.first; }
        } ;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, CompareGreat> latestTweet;
        for(auto [fUserId, yes] : follower[userId]){
            int postLen = posts[fUserId].size()-1;
            int time = posts[fUserId][postLen].first;
            latestTweet.push(make_pair(time,make_pair(fUserId, postLen)));
        }
        vector<int> sol;
        int tweetCount=10;
        while(latestTweet.size()>0 && tweetCount){
            auto [time, p] = latestTweet.top();
            auto [fuserId, postLen] = p;
            latestTweet.pop();
            sol.push_back(posts[fuserId][postLen].second);
            if(postLen>=1){
                latestTweet.push(make_pair(posts[fuserId][postLen-1].first,make_pair(fuserId, postLen-1)));
            }
            tweetCount--;
        }
        return sol;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        follower[followerId][followeeId]=0;
        
        follower[followerId].erase(followeeId);
    }
};
