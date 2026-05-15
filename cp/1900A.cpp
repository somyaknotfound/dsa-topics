/*
OBS:

- If "..." exists anywhere:
    -> 2 ops are enough.
    Why? Place on ends: W.W -> middle auto fills.
    Then use move-op freely to propagate.

- If no "..." exists:
    -> auto-fill never triggers.
    Why? no cell can ever have 2 watery neighbours.
    So every '.' must be filled manually.

ALGO:
1. count dots = cnt
2. scan for substring "..."
3. if found -> ans = 2
   else      -> ans = cnt

Edge:
cnt==0 => ans=0

TC: O(n)
*/





#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        string s;

        cin >> n >> s;

        int dots = 0;
        bool found = false;

        for (char c : s)
            if (c == '.') dots++;

        for (int i = 0; i + 2 < n; i++) {
            if (s[i] == '.' &&
                s[i + 1] == '.' &&
                s[i + 2] == '.') {

                found = true;
                break;
            }
        }

        if (found) cout << 2 << "\n";
        else cout << dots << "\n";
    }

    return 0;
}
