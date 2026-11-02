class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(),left=0,maxFq=0,maxLen=0;
        vector<int>freq(26,0);
        for(int right=0;right<n;right++)
        {
            freq[s[right]-'A']++;
            maxFq=max(maxFq,freq[s[right]-'A']);
            int len=right-left+1;
            if(len-maxFq<=k)
            {
                maxLen=max(maxLen,right-left+1);
            }
            else{
                freq[s[left]-'A']--;
                left++;
                maxFq=0;
                for(int x:freq) maxFq=max(maxFq,x);
            }
        }
        return maxLen;

    }
};