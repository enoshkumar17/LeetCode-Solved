class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size(),top1,top2;
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*")
            {
                top1=st.top();st.pop();
                top2=st.top();st.pop();
                switch(tokens[i][0])
                {
                    case '+': st.push(top1+top2);
                                break;
                    case '-': st.push(top2-top1);
                            break;
                    case '*': st.push(top1*top2);
                            break;
                    case '/': st.push(top2/top1);
                            break;
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};