class Twitter {
    struct Node {
        // ��ϣ��洢��ע�˵� Id
        unordered_set<int> followee;
        // ������洢 tweetId
        list<int> tweet;
    };
    // getNewsFeed ���������ĵ������Լ� tweetId ��ʱ���
    int recentMax, time;
    // tweetId ��Ӧ���͵�ʱ��
    unordered_map<int, int> tweetTime;
    // ÿ���û��洢����Ϣ
    unordered_map<int, Node> user;
public:
    Twitter() {
        time = 0;
        recentMax = 10;
        user.clear();
    }
    
    // ��ʼ��
    void init(int userId) {
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }

    void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end()) {
            init(userId);
        }
        // �ﵽ���ƣ��޳�����ĩβԪ��
        if (user[userId].tweet.size() == recentMax) {
            user[userId].tweet.pop_back();
        }
        user[userId].tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans; ans.clear();
        for (list<int>::iterator it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it) {
            ans.emplace_back(*it);
        }
        for (int followeeId: user[userId].followee) {
            if (followeeId == userId) continue; // ���ܳ����Լ���ע�Լ������
            vector<int> res; res.clear();
            list<int>::iterator it = user[followeeId].tweet.begin();
            int i = 0;
            // ���Թ鲢
            while (i < (int)ans.size() && it != user[followeeId].tweet.end()) {
                if (tweetTime[(*it)] > tweetTime[ans[i]]) {
                    res.emplace_back(*it);
                    ++it;
                } else {
                    res.emplace_back(ans[i]);
                    ++i;
                }
                // �Ѿ��ҵ����������������������� recentMax ������
                if ((int)res.size() == recentMax) break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i) res.emplace_back(ans[i]);
            for (; it != user[followeeId].tweet.end() && (int)res.size() < recentMax; ++it) res.emplace_back(*it);
            ans.assign(res.begin(),res.end());
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (user.find(followerId) == user.end()) {
            init(followerId);
        }
        if (user.find(followeeId) == user.end()) {
            init(followeeId);
        }
        user[followerId].followee.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
    }
};


