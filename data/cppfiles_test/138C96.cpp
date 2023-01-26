#include <bits/stdc++.h>
using namespace std;
struct node {
  long long l, r, tot, ans;
  node() {}
  node(long long a, long long b, long long c, long long d) {
    l = a;
    r = b;
    tot = c;
    ans = d;
  }
};
long long calc(vector<long long>& pre, long long l, long long r, long long k) {
  l = r - k + 1;
  assert(l >= 0);
  long long res = pre[r];
  if (l) res -= pre[l - 1];
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  vector<pair<long long, long long>> v;
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    res += x;
    v.push_back({x, 1});
  }
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    v.push_back({x, 0});
  }
  sort(v.begin(), v.end());
  vector<node> D(n + m);
  vector<long long> pre(n + m);
  for (long long i = 0; i < n + m; i++) {
    D[i] = node(i, i, v[i].second, v[i].first * v[i].second);
  }
  vector<pair<long long, long long>> ed;
  pre[0] = v[0].first;
  for (long long i = 1; i < n + m; i++) {
    ed.push_back({v[i].first - v[i - 1].first, i - 1});
    pre[i] = pre[i - 1] + v[i].first;
  }
  sort(ed.begin(), ed.end());
  vector<long long> ans(q);
  vector<pair<long long, long long>> qry;
  for (long long i = 0; i < q; i++) {
    long long k;
    cin >> k;
    qry.push_back({k, i});
  }
  sort(qry.begin(), qry.end());
  long long i = 0;
  for (auto p : qry) {
    long long k = p.first;
    long long idx = p.second;
    cerr << k << '\n';
    while (i < n + m - 1 && ed[i].first <= k) {
      long long wh = ed[i].second;
      res -= D[wh].ans;
      res -= D[wh + 1].ans;
      long long ll = D[wh].l;
      long long rr = D[wh + 1].r;
      long long tt = D[wh].tot + D[wh + 1].tot;
      long long val = calc(pre, ll, rr, tt);
      node d(ll, rr, tt, val);
      res += val;
      D[ll] = d;
      D[rr] = d;
      i++;
    }
    ans[idx] = res;
  }
  for (long long i = 0; i < q; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
