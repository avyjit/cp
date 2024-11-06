#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define MOD ((ll)(1e9 + 7))
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<ll, ll> pll;

#define umap unordered_map
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
#define each(x, a) for (auto &x : a)
template <typename T> void print(T v) { cout << v << endl; }
template <typename T> void print(vector<T> v) { each(x, v) cout << x << " "; cout << endl; }

ll dp(ll len, ll chefs_turn, vec<vec<ll>> &cache) {

  if (chefs_turn) {
    if (len == 1) return 1;
    else if (len == 2) return 1;
    else if (len == 3 || len == 4) return len;
  }

  if (len <= 0) return 0;

  if (cache[len][chefs_turn] != -1) 
    return cache[len][chefs_turn];
  
  ll ways = dp(len-1, 1 - chefs_turn, cache) % MOD;
  for (ll k=2; k<=4; ++k) {
    ways += dp(len-k, chefs_turn, cache);
    ways %= MOD;
  }

  ways %= MOD;

  return cache[len][chefs_turn] = ways;
}

void solve() {
  ll n; cin >> n;

  gridv(ll, cache, n+1, 2, -1);
  ll ans = dp(n, 1, cache);
  print(ans);

}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}