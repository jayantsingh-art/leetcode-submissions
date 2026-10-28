class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto pair : prerequisites) {
            int u = pair[0];
            int v = pair[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(auto neigh : adj[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        return count == n;
    }
};