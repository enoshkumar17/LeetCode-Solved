class Solution {
public:
    void generate(int open,int close,string s,vector<string>&ans,int n)
    {
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }
        if(open!=n) generate(open+1,close,s+"(",ans,n);
        if(close<open) generate(open,close+1,s+")",ans,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(0,0,"",ans,n);
        return ans;
    }
};