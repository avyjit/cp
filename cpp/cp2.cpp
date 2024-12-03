#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

/* --- <SNIPPET> --- */

/* --- </SNIPPET> --- */

//#define MOD ((ll)(1e9 + 7))
#define MOD 998244353
using ll = long long;
using ull = unsigned long long;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<ll, ll> pll;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }


template <typename K, typename V>
using umap = gp_hash_table<K, V, custom_hash>;

template <typename T>
using uset = umap<T, null_type>;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vec vector
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i=0; i<n; ++i)
#define rep1(i, n) for (ll i=1; i<=n; ++i)
#define rev(i, n) for (ll i=n; i>=0; --i)
#define grid(type, name, m, n) vec<vec<type>> name(m, vec<type>(n))
#define gridv(type, name, m, n, v) vec<vec<type>> name(m, vec<type>(n, v))
#define grid3(type, name, p, q, r, val) vec<vec<vec<type>>> name(p, vec<vec<type>>(q, vec<type>(r, val)))
#define each(x, a) for (auto &x : a)
template <typename T> void print(T v) { cout << v << endl; }
template <typename T> void print(vector<T> v) { each(x, v) cout << x << " "; cout << endl; }
template <typename T> void print(vector<vector<T>> v) { each (r, v) print(r); }

#ifdef LOCAL
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    
}

signed main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  ll t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}