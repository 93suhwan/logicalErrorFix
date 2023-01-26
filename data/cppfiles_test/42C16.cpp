#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
struct fwt {
  int n;
  vector<ll> st;
  fwt(int n) : n(n), st(n + 1) {}
  void upd(int t, ll v) {
    while (t <= n) st[t] = (st[t] + v) % MOD, t += t & -t;
  }
  ll get(int t) {
    ll r = 0;
    while (t) r = (r + st[t]) % MOD, t -= t & -t;
    return r;
  }
};
vector<pair<int, int>> p;
vector<ll> d;
struct myset {
  ll sum = 0;
  set<pair<int, int>> l, r;
  void push(int i) {
    l.emplace(p[i].first, i);
    r.emplace(p[i].second, i);
    sum = (sum + d[i]) % MOD;
  }
  void del(int i) {
    l.erase({p[i].first, i});
    r.erase({p[i].second, i});
    sum = (sum - d[i] + MOD) % MOD;
  }
  void cutleft(int s) {
    while (l.size() && l.begin()->first <= s) del(l.begin()->second);
  }
  void cutright(int e) {
    while (r.size() && r.rbegin()->first >= e) del(r.rbegin()->second);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  fwt fw(2 * n);
  p.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
  vector<int> in(n);
  for (int i = 0; i < n; i++) in[i] = i + 1;
  sort(in.begin(), in.end(),
       [&](int x, int y) { return p[x].second < p[y].second; });
  vector<int> chk(n + 1);
  int t;
  cin >> t;
  for (int i = 0, j; i < t; i++) cin >> j, chk[j] = 1;
  ll sum = 0;
  d.resize(n + 1);
  int re;
  for (int i = 0, j = 0; i < n; i++) {
    j += chk[in[i]];
    if (j == t) {
      re = in[i];
      break;
    }
    d[in[i]] =
        (MOD + 1 + fw.get(p[in[i]].second) - fw.get(p[in[i]].first)) % MOD;
    sum = (sum + d[in[i]]) % MOD;
    fw.upd(p[in[i]].first, d[in[i]]);
  }
  myset s1, s2;
  for (int i = 1; i <= n; i++)
    if (p[re].first < p[i].first && p[i].second < p[re].second) {
      s1.push(i);
      if (chk[i]) s2.push(i);
    }
  for (int i = re;;) {
    sum = (sum + 1) % MOD;
    if (s2.l.empty()) break;
    int j = s2.r.rbegin()->second;
    s1.cutright(p[j].second);
    sum = (sum + s1.sum) % MOD;
    s1.cutleft(p[j].first);
    s2.cutleft(p[j].first);
    s2.cutright(p[j].second);
    i = j;
  }
  cout << sum;
  return 0;
}
