#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast", "unroll-loops")
using namespace std;
const long long maxn = 8e5;
const long long maxn1 = 4e5;
vector<long long> z[maxn];
long long dp[maxn];
long long a[maxn];
long long t[4 * maxn];
long long get(long long node, long long tl, long long tr, long long pos) {
  if (tl > pos || tr <= pos) return (-1e18);
  if ((tr - tl) == 1) return t[node];
  long long tm = (tl + tr) / 2;
  return max({t[node], get(2 * node + 1, tl, tm, pos),
              get(2 * node + 2, tm, tr, pos)});
}
void to(long long node, long long tl, long long tr, long long l, long long r,
        long long val) {
  if (tl >= l && tr <= r) {
    t[node] = max(t[node], val);
    return;
  }
  if (tl >= r || tr <= l) {
    return;
  }
  long long tm = (tl + tr) / 2;
  to(2 * node + 1, tl, tm, l, r, val);
  to(2 * node + 2, tm, tr, l, r, val);
}
vector<pair<long long, long long> > r;
void go(long long x) {
  long long val = a[x];
  long long val2 = a[x] - x;
  r.push_back({val2 + maxn1 + 1, dp[x]});
}
void upd(long long x) {
  if (a[x] <= (x + 1)) {
    dp[x] = max(dp[x], 1LL);
  }
  long long val = a[x];
  long long val2 = a[x] - x;
  dp[x] = max(dp[x], get(0, 0, maxn, val2 + maxn1) + 1);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 4 * maxn; ++i) {
    t[i] = (-1e18);
  }
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    z[a[i]].push_back(i);
  }
  vector<pair<long long, long long> > z;
  for (long long i = 0; i < n; ++i) z.push_back({a[i], i});
  sort(z.begin(), z.end());
  for (long long i = 0; i < z.size(); ++i) {
    if (i == 0 || z[i].first != z[i - 1].first) {
      for (auto l : r) {
        to(0, 0, maxn, 0, l.first, l.second);
      }
      r.clear();
    }
    pair<long long, long long> h = z[i];
    upd(h.second);
    go(h.second);
  }
  cout << *max_element(dp, dp + n);
  return 0;
}
