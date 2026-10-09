class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int n=s.size(),i=0,insertion=0,depth=0;
        while(i<n)
        {
            if(s[i]=='(') st.push(s[i]);
            else 
            {
                if(!st.empty() && st.top()=='(')
                {
                    if(i<n-1 && s[i+1]==')') i++;
                    else insertion++;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            i++;
        }
        while(!st.empty())
        {
            if(st.top()=='(')
            {
                if(depth==0) insertion+=2;
                else if(depth==1) 
                {
                    insertion++;
                    depth--;
                }
                else{
                    depth-=2;
                }
            }
            else {
                depth++;
            }
            st.pop();
        }
        if(depth>0)
        {
            if(depth%2==0) insertion+=depth/2;
            else{
                insertion+=depth/2+2;
            }
        }
        return insertion;
    }
};