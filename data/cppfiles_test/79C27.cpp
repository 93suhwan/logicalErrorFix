#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
long long a[300005], b[300005], d[300005], c[300005], pre[300005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
  }
  set<pair<long long, pair<long long, long long> > > p, s;
  s.insert({n - a[n], {n, n}});
  p.insert({0, {n, n}});
  memset(d, 0x3f, sizeof(d));
  memset(c, 0x3f, sizeof(c));
  d[n] = 0;
  c[n] = 0;
  for (long long i = n - 1; i >= 0; i--) {
    while (s.size()) {
      long long u = s.rbegin()->first;
      pair<long long, long long> w = s.rbegin()->second;
      if (u > i) {
        s.erase({u, w});
        p.erase({c[w.first], w});
      } else
        break;
    }
    if (p.size()) {
      if (d[i] > p.begin()->first + 1) {
        d[i] = p.begin()->first + 1;
        pre[i] = p.begin()->second.second;
      }
    }
    long long v = i + b[i];
    if (c[v] > d[i]) {
      c[v] = d[i];
      s.insert({v - a[v], {v, i}});
      p.insert({c[v], {v, i}});
    }
  }
  if (d[0] > 1e18) {
    cout << -1 << endl;
    return 0;
  }
  cout << d[0] << endl;
  long long now = 0;
  vector<long long> ans;
  while (now < n) {
    ans.push_back(now);
    now = pre[now];
  }
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
}
