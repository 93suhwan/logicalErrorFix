#include <bits/stdc++.h>
using namespace std;
void getdepth(long long cur, vector<long long>& d, vector<long long>& pr,
              vector<vector<long long> >& ed) {
  d[cur] = d[pr[cur]] + 1;
  for (auto to : ed[cur]) {
    if (to == pr[cur]) continue;
    pr[to] = cur;
    getdepth(to, d, pr, ed);
  }
}
long long mark(long long cur, vector<bool>& marked, vector<long long>& pr) {
  if (marked[cur]) return 0;
  long long cnt = 1;
  marked[cur] = true;
  cnt += mark(pr[cur], marked, pr);
  return cnt;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long> > ed(n + 1);
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    ed[u].push_back(v);
    ed[v].push_back(u);
  }
  vector<long long> d(n + 1);
  vector<long long> pr(n + 1);
  pr[1] = 1;
  getdepth(1, d, pr, ed);
  vector<pair<long long, long long> > order;
  for (long long i = 1; i <= n; ++i) order.push_back(make_pair(d[i], i));
  sort((order).rbegin(), order.rend());
  vector<pair<long long, long long> > c;
  vector<bool> marked(n + 1);
  for (long long i = 0; i < n; ++i) {
    long long x = mark(order[i].second, marked, pr);
    c.push_back(make_pair(x, order[i].second));
  }
  sort((c).rbegin(), c.rend());
  long long ans = -1000000000000000000ll;
  long long sm = 0;
  for (long long i = 0; i < k; ++i) {
    long long r = i + 1;
    sm += c[i].first;
    long long b = min(n / 2, n - sm);
    long long cur = (n - r - b) * (r - b);
    ans = max(ans, cur);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tst;
  tst = 1;
  while (tst--) {
    solve();
  }
  return 0;
}
