#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll
log2_floor (uint64_t i)
{
  return i ? __builtin_clzll (1) - __builtin_clzll (i) : -1;
}

constexpr size_t MAXN = 2e5 + 4;
constexpr size_t K = 25;

/* sparse table */
ll st[K + 1][MAXN];

void
init (ll a[], ll N)
{
  copy (a, a + N, st[0]);

  for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
      st[i][j] = min (st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

ll
query (ll l, ll r)
{
  ll i = log2_floor (r - l + 1);
  return min (st[i][l], st[i][r - (1 << i) + 1]);
}

#define dbg(...) // printf(__VA_ARGS__)

void
solve (ll a[], ll n)
{
  init (a, n);
  ll mxl = a[0], mxr = a[n - 1], l = 0, r = n - 1;

  while (r - l - 1 > 0)
    {
      dbg ("%lld %lld %lld %lld\n", l, r, mxl, mxr);
      if (mxl != mxr)
        {
          if (mxl < mxr)
            {
              mxl = max (mxl, a[++l]);
            }
          else
            {
              mxr = max (mxr, a[--r]);
            }

          continue;
        }

      ll q = query (l + 1, r - 1);
      dbg ("q=%lld\n", q);
      if (query (l + 1, r - 1) == mxl)
        {
          puts ("YES");
          ll x = l + 1;
          ll y = r - l - 1;
          printf ("%lld %lld %lld\n", x, y, n - (x + y));
          return;
        }
      else
        {
          if (q > mxl)
            {
              if (a[l + 1] > a[r - 1])
                mxl = max (mxl, a[++l]);
              else
                mxr = max (mxr, a[--r]);
            }
          else
            {
              if (a[l + 1] > a[r - 1])
                mxr = max (mxr, a[--r]);
              else
                mxl = max (mxl, a[++l]);
            }
        }
    }

  puts ("NO");
}

signed
main ()
{
  ll t;
  scanf ("%lld", &t);

  while (t--)
    {
      ll n;
      scanf ("%lld", &n);
      ll a[n];
      for (ll i = 0; i < n; ++i)
        scanf ("%lld", &a[i]);

      solve (a, n);
    }

  return 0;
}