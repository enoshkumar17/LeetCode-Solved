class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size();
        int minLen = n + 1;
        long long sum = 0;

        for(int right = 0; right < n; right++) {
            sum += nums[right];

            while(sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLen == n + 1 ? 0 : minLen;
    }
};