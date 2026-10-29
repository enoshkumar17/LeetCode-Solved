class Solution {
public:// see one approach is double loop , checking if right side has any bigger one
    int maxProfit(vector<int>& prices) {
        int max_profit=0,n=prices.size(),min=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
            }
            else{
                max_profit=max(max_profit,prices[i]-min);
            }
        }
        return max_profit;
    }
};