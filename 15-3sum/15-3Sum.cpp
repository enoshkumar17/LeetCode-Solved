class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = n - 1;
            int target = -nums[i];

            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    int left = nums[l], right = nums[r];

                    while (l < r && nums[l] == left) l++;
                    while (l < r && nums[r] == right) r--;
                }
                else if (sum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }

        return ans;
    }
};