class Solution {
public:
    bool ispalindrome(int start,int end,string s){
        while(start<=end){
            if(s[start]!=s[end])
              return false;
            start++;
            end--;
        }
        return true;
    }
    void solve( vector<vector<string>>&ans,vector<string> temp,string s,int start){
        if(start==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(ispalindrome(start,i,s)){
                temp.push_back(s.substr(start,i-start+1));
                solve(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,temp,s,0);
        return ans;
    }
};