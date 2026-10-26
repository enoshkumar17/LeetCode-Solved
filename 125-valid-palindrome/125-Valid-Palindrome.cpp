class Solution {
public:
    bool isPalindrome(string s) {
        
        string modified="";
        for(char c:s)
        {
            c=tolower(c);
            if((c>='a' && c<='z')or(c>='0' && c<='9'))
                modified+=c;
        }
        string temp = modified;
        reverse(modified.begin(),modified.end());
        return temp==modified;
    }
};