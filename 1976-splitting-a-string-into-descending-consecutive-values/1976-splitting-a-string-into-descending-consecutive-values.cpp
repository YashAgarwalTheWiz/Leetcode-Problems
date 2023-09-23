class Solution {
    int n;
    bool split(int idx, string &s, unsigned long long num)
    {
        if(idx == n)
            return true;
        string ans = "";
        for(int i = idx; i < n; i++)
        {
            ans += s[i];
            unsigned long long val = stoull(ans);
            if(val != num-1)
                continue;
            if(split(i+1, s, val))
                return true;
        }
        return false;
    }
public:
    bool splitString(string s) {
        n = s.size();
        string ans = "";
        for(int i = 0; i < n-1; i++)
        {
            ans += s[i];
            unsigned long long num = stoull(ans);
            if(split(i+1, s, num))
            {
                return true;
            }
        }
        return false;
    }
};