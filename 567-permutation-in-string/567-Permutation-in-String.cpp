class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0,n1=s1.size(),n2=s2.size(),i=0,match=0;
        if(n1>n2) return false;
        vector<int>str1(26,0),str2(26,0);
        for(char c:s1) str1[c-'a']++;
        for(int i=0;i<n1;i++) str2[s2[i]-'a']++;
        for(int i=0;i<26;i++) match += str1[i]==str2[i]? 1:0;
        int right=n1;
        while(right<n2)
        {
            if(match==26) return true;
            else{
                if(str2[s2[left]-'a']==str1[s2[left]-'a']) match--;
                //matched before removing -> -1
                str2[s2[left]-'a']--;
                //matched after removing -> +1
                if(str2[s2[left]-'a']==str1[s2[left]-'a']) match++;


                if(str2[s2[right]-'a']==str1[s2[right]-'a']) match--;
                //matched before adding -> -1
                str2[s2[right]-'a']++;
                //matched FTER ADDING -> +1
                if(str2[s2[right]-'a']==str1[s2[right]-'a']) match++;
                
                left++;
                right++;
            }
        }
        return (match==26);
    }
};