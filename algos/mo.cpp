#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define umap unordered_map
#define vll vector<ll>


struct Query {
    int l, r, idx;
    int64_t ord;

    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {
      ord = gilbertOrder(l, r, 21, 0);
    }

    bool operator<(Query other) const
    {
      return ord < other.ord;
    }

    static inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
        if (pow == 0) {
            return 0;
        }
        int hpow = 1 << (pow-1);
        int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
        ) : (
            (y < hpow) ? 1 : 2
        );
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        int64_t subSquareSize = int64_t(1) << (2*pow - 2);
        int64_t ans = seg * subSquareSize;
        int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
        ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
        return ans;
    }
};

struct Mo {
  vll &a;
  umap<ll, ll> frq;
  ll count;

  Mo(vll &a) : a(a), count(0) {}

  void add(ll i) {

  }
  void remove(ll i) {

  }  

  ll compute() {

  }

  vector<ll> solve(vector<Query> &queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
  
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers.at(q.idx) = compute(); 
    }
    return answers;
  }
};


