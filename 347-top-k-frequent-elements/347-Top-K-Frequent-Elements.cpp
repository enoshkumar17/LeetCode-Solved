class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==0) return {};
        unordered_map<int,int>mp;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int x:nums)
            mp[x]++;
        for(auto it:mp)
            pq.push({it.second,it.first});
        while(k-- && !pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};