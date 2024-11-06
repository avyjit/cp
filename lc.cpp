#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n, 0);
    printf("n = %d, q = %d\n", n, q);
    while (q--) {
        int l, r, u;
        cin >> l >> r >> u;
        a[l] += u;
        if (r+1 < n) 
            a[r+1] -= u;
    }

    partial_sum(a.begin(), a.end(), a.begin());
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }
}