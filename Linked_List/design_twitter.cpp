class Twitter {
public:
    unordered_map<int, set<int>> friends;
    priority_queue<vector<int>> newsFeed;
    int curr;

    Twitter() {
        curr = 0;
        friends.clear();
        newsFeed = priority_queue<vector<int>>();
    }

    void postTweet(int userId, int tweetId) {
        newsFeed.push({curr++, userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        int n = 0;
        vector<int> ans;
        priority_queue<vector<int>> news = newsFeed;

        while (!news.empty() && n < 10) {

            auto tweet = news.top();
            news.pop();
            if (tweet[1] == userId || 
            friends[userId].count(tweet[1])) {
                ans.push_back(tweet[2]);
                n++;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
