bool vis[N];

void dfs(int vertex) {

    // 1. Action after entering the vertex

    vis[vertex] = true;

    for (int child : g[vertex]) {

        // 2. Action before entering the child

        dfs(child);

        // 3. Action after exiting the child
    }

    // 4. Action before exiting the vertex
}
