class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>newg(graph.size());
        vector<int>indeg(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto j:graph[i]){
                newg[j].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0)
              q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:newg[front]){
                if(--indeg[i]==0)
                  q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};