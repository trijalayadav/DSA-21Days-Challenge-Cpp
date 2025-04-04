class Solution
{
public:
    void dfs(int node, int parent, int &timer, vector<int> &disc,
             vector<int> &low, vector<vector<int>> &result,
             vector<vector<int>> &adj, vector<bool> &visited)
    {

        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (int neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;

            if (!visited[neighbor])
            {
                dfs(neighbor, node, timer, disc, low, result, adj, visited);
                low[node] = min(low[node], low[neighbor]);

                // Check for bridge
                if (low[neighbor] > disc[node])
                {
                    result.push_back({node, neighbor});
                }
            }
            else
            {
                // Back edge
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        vector<vector<int>> result;

        // Build the adjacency list
        for (const auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<bool> visited(n, false);
        int timer = 0;

        // Run DFS for all components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, timer, disc, low, result, adj, visited);
            }
        }

        return result;
    }
};
