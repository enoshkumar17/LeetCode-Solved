class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>PS(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
            PS[i]={position[i],speed[i]};
        sort(PS.begin(),PS.end());
        st.push(PS[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            auto curr=PS[i];
            double t1=(double)(target-curr.first)/curr.second;
            auto top=st.top();
            double t2=(double)(target-top.first)/top.second;
            if(t1 > t2)
            {
                st.push(curr);
            }
        }
        return st.size();
    }
};