class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> h(256, 0);

        for(char c : t) h[c]++;

        int left = 0, n = s.size(), minLen = n+1,start;

        for(int right = 0; right < n; right++) {
            h[s[right]]--;

            bool flag = true;

            if((right-left+1) >= t.size()) {

                for(int x : h) {
                    if(x > 0) {
                        flag = false;
                        break;
                    }
                }

                while(flag) {
                    if(minLen > right-left+1) {
                        minLen = right-left+1;
                        start=left;
                    }

                    h[s[left]]++;

                    if(h[s[left]] > 0)
                        flag = false;

                    left++;
                }
            }
        }

        return minLen == n+1 ? "" : s.substr(start, minLen);
    }
};