class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        for(int i=0;i<n-1;i++)
        {
            st.push({temperatures[i],i});
            if(temperatures[i]<temperatures[i+1])
            {
                st.pop();
                ans[i]=1;
                while(!st.empty())
                {
                    auto it=st.top();
                    int temp=it.first;
                    int ind=it.second;
                    if(temp<temperatures[i+1])
                    {
                        st.pop();
                        ans[ind]=i-ind+1;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};