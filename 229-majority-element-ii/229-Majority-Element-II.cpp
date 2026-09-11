class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=nums[0],el2=-el1,cnt1=1,cnt2=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=el1 && cnt2==0)
            {
                el2=nums[i];
                cnt2++;
            }
            else if(nums[i]!=el2 && cnt1==0)
            {
                el1=nums[i];
                cnt1++;
            }
            else if(nums[i]==el1)
                cnt1++;
            else if(nums[i]==el2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el1)
                cnt1++;
            else if(nums[i]==el2)
                cnt2++;
        }
        if(cnt1>(n/3) && cnt2>(n/3))
            return {el1,el2};
        if(cnt1>(n/3))
            return {el1};
        else if(cnt2>(n/3))
            return {el2};
        return {};
    }
};