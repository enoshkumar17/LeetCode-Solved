class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>s;
        int k=0;
        for(int x:nums)
            s[x]=k++;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(s.count(target-nums[i]) && s[target-nums[i]]!=i)
                    return {i,s[target-nums[i]]};
        }
        return {0,0};

    }
};