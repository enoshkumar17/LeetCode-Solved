class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n=s.size(),i=0,l=n;
        vector<int>p;
        while(l--)
        {
            
            if(s[i]==')' && st.top()=='(')
            {
                st.pop();
            }
            else st.push(s[i]);
            if(st.empty())
            {
                p.push_back(i);
            }
            i++;
        }
        string ans;
        int j=1,k=0,n1=p.size();
        while(j<n && k<n1)
        {
            if(j==p[k])
            {
                k++;
                j++;
            }
            else{
                ans+=s[j];
            }
            j++;
        }
        return ans;
    }
};