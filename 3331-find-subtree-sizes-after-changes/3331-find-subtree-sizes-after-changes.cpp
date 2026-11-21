
class Solution {
public:

    vector<vector<int>> adj, newAdj;
    vector<int> newParent, ans;
    int last[26];

    // DFS 1: Find the new parent
    void dfs1(int node, string &s) {

        int c = s[node] - 'a';

        int previous = last[c];

        // Find nearest ancestor with same character
        if (last[c] != -1) {
            newParent[node] = last[c];
        }

        // Update latest ancestor
        last[c] = node;

        for (int child : adj[node]) {
            dfs1(child, s);
        }

        // Backtrack
        last[c] = previous;
    }

    // DFS 2: Calculate subtree size
    int dfs2(int node) {

        int size = 1;

        for (int child : newAdj[node]) {
            size += dfs2(child);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        newAdj.resize(n);

        newParent = parent;
        ans.resize(n);

        // Step 1: Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Step 2: Initialize last array
        fill(last, last + 26, -1);

        // Step 3: Find new parents
        dfs1(0, s);

        // Step 4: Build modified tree
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Step 5: Calculate subtree sizes
        dfs2(0);

        return ans;
    }
};
