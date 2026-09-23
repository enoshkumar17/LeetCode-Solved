class Solution {
public:
    // 1-> recursion

    // int solve(vector<int>&nums,int l,int h, int x)
    // {
    //     if(x==0) return h-l+1;
    //     if(l>h || x<0) return -1;
    //     return max(solve(nums,l+1,h,x-nums[l]),solve(nums,l,h-1,x-nums[h]));
    // }
    // int minOperations(vector<int>& nums, int x) {
    //     int n=nums.size();
    //     int ans = solve(nums,0,n-1,x);
    //     return (ans==-1) ? -1: n-ans;
    // }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = 0;
        for (int y : nums)
            sum += y;

        int targetWindow = sum - x;

        if (targetWindow == 0)
            return n;

        int l = 0, r = 0;
        int currWindow = 0;
        int ans = n + 1;

        while (r < n) {
            currWindow += nums[r];
            r++;

            while (currWindow > targetWindow && l < r) {
                currWindow -= nums[l];
                l++;
            }

            if (currWindow == targetWindow) {
                ans = min(ans, n - (r - l));
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};