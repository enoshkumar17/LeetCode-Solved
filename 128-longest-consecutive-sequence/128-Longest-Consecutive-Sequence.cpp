class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int>pq;
        for(int x:nums)
            pq.push(x);
        int ans=0,count=1;
        while(!pq.empty())
        {
            int temp=pq.top();
            pq.pop();
            if(!pq.empty() && pq.top()==temp-1)
            {
                count++;
            }
            else if (!pq.empty() && pq.top()==temp)
            {
                continue;
            }
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        return ans;
    }
};