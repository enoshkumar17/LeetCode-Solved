class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,n=height.size(),r=n-1;
        int maxArea=0;
        while(l<r)
        {
            maxArea=max(maxArea,(r-l)*min(height[l],height[r]));
            if(min(height[l],height[r])==height[l]) l++;
            else r--;
        }
        return maxArea;
    }
};