https://leetcode.com/contest/weekly-contest-458/problems/minimize-maximum-component-cost/submissions/1701093548/

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    int find(int u, vector<int>& parent) {
        while (u != parent[u]) {
            parent[u] = parent[parent[u]]; // Path compression
            u = parent[u];
        }
        return u;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        sort(edges.begin(), edges.end(), cmp);

        int components = n;
        int maxEdge = 0;
        if (components <= k) return maxEdge;
        for (const auto& edge : edges) {
            

            int u = find(edge[0], parent);
            int v = find(edge[1], parent);

            if (u != v) {
                
                if (rank[u] < rank[v]) {
                    parent[u] = v;
                } else if (rank[u] > rank[v]) {
                    parent[v] = u;
                } else {
                    parent[v] = u;
                    rank[u]++;
                }
                components--;
                maxEdge = edge[2];
                if (components <= k) break;
            }
        }

        return maxEdge;
    }
};