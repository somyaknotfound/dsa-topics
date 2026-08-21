class DisjointSet {
    vector <int> rank , size, parent;

    public:

    DisjointSet(int n) {
        rank.resize(n+1 , 0);
        size.resize(n+1);
        parent.resize(n+1);
        for (int i = 0 ; i <= n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u , int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if (ult_u == ult_v) return;

        if (rank[ult_u] < rank[ult_v]) parent[ult_u] = ult_v;
        else if(rank[ult_u] > rank[ult_v]) parent[ult_v] = ult_u;
        else {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }

    }

    void unionBySize(int u , int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) parent[ulp_u] = ulp_v;
        else if (size[ulp_u] > size[ulp_v]) parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       
        

        vector <pair<int, pair<int,int>>> edges;

        for (int i = 0 ; i < V ; i++) {
            for (auto it: adj[i]) {
                int v = it[0];
                int wt = it[1];
                int u = i;
                edges.push_back({wt,{u,v}});
            }
        }

        sort(edges.begin() , edges.end());

        DisjointSet ds(V);

        int sum = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v =it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                sum+= wt;

                ds.unionBySize(u,v);
            }
        }

        return sum;
       
    }
};
