// Problem
// Fatland is a town that started with N distinct empires, namely empires 1, 2, ..., N. But over time, the armies of some of these empires have taken over other ones. Each takeover occurred when the army of empire i invaded empire j. After each invasion, all of empire j became part of empire i, and empire j was renamed as empire i.

// Empire Huang, leader of Badland, wants to invade Fatland. To do this, he needs to calculate how many distinct empires still remain in Fatland after all the takeovers. Help him with this task.

// Input:

// The first line contains an integer N, the number of empires that were originally in Fatland.

// The second line contains an integer K, denoting the number of takeovers that took place.

// Each of the next K lines contains 2 space-separated integers i, j, representing that the army of empire i took over that of empire j. As a result, empire j does not exist anymore and is now renamed as empire i. It is guaranteed that empire i still exists.

// Output: Output one integer, the number of empires that exist in Fatland.

// Constraints:

// 1 <= N <= 105

// 1 <= K <= 105


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int parent[N];
int sz[N];

void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void Union(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // Initialize all N elements
    for (int i = 1; i <= n; i++) {
        make(i);
    }

    while (k--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int ct = 0;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i) ct++;
    }

    cout << ct << "\n";

    return 0;
}
