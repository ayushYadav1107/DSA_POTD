class Solution
{
public:
    typedef pair<int, int> P;

    int minCost(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<P>> adj;

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt * 2}); // reversed edge
        }

        priority_queue<P, vector<P>, greater<P>> pq; // max-heap
        vector<int> result(n, INT_MAX);              // result[i] = distance of S is 0 with node i
        result[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1)
            {
                return result[n - 1];
            }

            for (auto &p : adj[node])
            {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode])
                {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
        return -1;
    }
};