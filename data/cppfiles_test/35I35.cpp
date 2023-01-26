#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
using namespace std;
const long long maxn = 1e6 + 5;
long long n;
bool used[maxn];
vector<long long> v[maxn];
vector<long long> g[maxn];
long long t[4 * maxn];
void init() {
  used[0] = true;
  used[1] = true;
  for (long long i = 2; i < maxn; ++i) {
    if (used[i]) continue;
    v[i] = {i};
    for (long long j = 2 * i; j < maxn; j += i) {
      used[j] = true;
      v[j].push_back(i);
    }
  }
}
vector<long long> slv(vector<pair<long long, long long> > z) {
  vector<long long> f;
  for (auto h : z) f.push_back(h.second);
  long long pr[f.size() + 1];
  pr[0] = 0;
  for (long long i = 0; i < f.size(); ++i) pr[i + 1] = pr[i] + f[i];
  stack<pair<long long, long long> > o;
  long long ans[f.size() + 1];
  for (long long i = 0; i <= f.size(); ++i) ans[i] = 1e9;
  for (long long i = 0; i <= f.size(); ++i) {
    while (true) {
      if (o.empty()) {
        o.push({pr[i], i});
        break;
      }
      pair<long long, long long> z = o.top();
      if (z.first <= pr[i]) {
        o.push({pr[i], i});
        break;
      } else {
        ans[z.second] = i;
        o.pop();
      }
    }
  }
  vector<long long> res;
  for (long long i = 0; i < f.size(); ++i) {
    if (ans[i] == 1e9)
      res.push_back(n);
    else
      res.push_back(z[ans[i] - 1].first);
  }
  return res;
}
void to(long long node, long long tl, long long tr, long long l, long long r,
        long long val) {
  if (tl >= l && tr <= r) {
    t[node] = min(t[node], val);
    return;
  }
  if (tl >= r || tr <= l) {
    return;
  }
  long long tm = (tl + tr) / 2;
  to(2 * node + 1, tl, tm, l, r, val);
  to(2 * node + 2, tm, tr, l, r, val);
}
long long get(long long node, long long tl, long long tr, long long pos) {
  if (tl > pos || tr <= pos) return 1e18;
  long long ans = t[node];
  if ((tr - tl) == 1) return ans;
  long long tm = (tl + tr) / 2;
  ans = min(ans, get(2 * node + 1, tl, tm, pos));
  ans = min(ans, get(2 * node + 2, tm, tr, pos));
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 4 * maxn; ++i) t[i] = 1e18;
  init();
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;
  for (long long i = 0; i < n; ++i)
    for (auto h : v[a[i]]) g[h].push_back(i);
  vector<pair<pair<long long, long long>, long long> > o;
  for (long long i = 2; i < maxn; ++i) {
    if (g[i].empty()) continue;
    vector<pair<long long, long long> > z;
    long long o1 = 0;
    for (auto j : g[i]) {
      long long x = a[j];
      assert(x % i == 0);
      while (x % i == 0) {
        ++o1;
        x /= i;
      }
      if (s[j] == '*')
        z.push_back({j, o1});
      else
        z.push_back({j, -o1});
    }
    vector<long long> t = slv(z);
    for (long long i = 0; i < z.size(); ++i) {
      if (i == 0)
        o.push_back({{0, z[0].first + 1}, t[i]});
      else
        o.push_back({{z[i - 1].first + 1, z[i].first + 1}, t[i]});
    }
  }
  to(0, 0, n, 0, n, n);
  for (auto l : o) to(0, 0, n, l.first.first, l.first.second, l.second);
  long long res = 0;
  for (long long i = 0; i < n; ++i) {
    long long val = get(0, 0, n, i);
    res += max(0LL, val - i);
  }
  cout << res << endl;
  return 0;
}
