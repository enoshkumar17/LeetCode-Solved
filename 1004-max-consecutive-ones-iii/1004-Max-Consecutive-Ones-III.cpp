class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,n=nums.size(),maxLen=0,zeros=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]==0) zeros++;
            if(zeros<=k)
                maxLen=max(maxLen,right-left+1);
            else{
                if (nums[left]==0) zeros--;
                left++;
            }
        }
        return maxLen;
    }
};