class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto el : prerequisites) {
            int u = el[0];
            int v = el[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto neigh : adj[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return ans.size() == n ? ans : vector<int>{};
    }
};