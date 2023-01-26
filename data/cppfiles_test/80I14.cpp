#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long N = 1e6 + 100, K = 31, INF = 2e18, MOD = 1e9 + 7;
long long t, n, m, a[N], b[N], p[N], s[N], fen[2 * N];
vector<long long> ad[N];
long long get(long long v) {
  long long res = 0;
  for (; v <= n + m; v |= v + 1) {
    res += fen[v];
  }
  return res;
}
void add(long long v) {
  for (; v >= 0; v = (v & (v + 1)) - 1) {
    fen[v]++;
  }
}
void f(long long ln, long long rn, long long lm, long long rm) {
  if (lm > rm || ln > rn) return;
  long long mm = (rm + lm) / 2;
  p[ln] = 0;
  for (long long i = ln + 1; i <= rn; i++) {
    p[i] = p[i - 1];
    if (a[i - 1] > b[mm]) {
      p[i]++;
    }
  }
  s[rn + 1] = 0;
  for (long long i = rn; i >= ln; i--) {
    s[i] = s[i + 1];
    if (a[i] < b[mm]) {
      s[i]++;
    }
  }
  long long mn = INF, pos = -1;
  for (long long i = ln; i <= rn; i++) {
    if (mn > p[i] + s[i]) {
      mn = p[i] + s[i];
      pos = i;
    }
  }
  ad[pos].push_back(b[mm]);
  if (lm == rm) return;
  f(ln, pos, lm, mm - 1);
  f(pos, rn, mm + 1, rm);
}
void solve() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(b, b + m);
    vector<long long> v;
    for (long long i = 0; i <= n; i++) {
      ad[i].clear();
    }
    f(0, n, 0, m - 1);
    for (long long i = 0; i <= n; i++) {
      sort(ad[i].begin(), ad[i].end());
    }
    for (long long i = 0; i < n; i++) {
      for (long long x : ad[i]) {
        v.push_back(x);
      }
      v.push_back(a[i]);
    }
    for (long long x : ad[n]) {
      v.push_back(x);
    }
    vector<long long> e = v;
    sort(e.begin(), e.end());
    map<long long, long long> ma;
    for (long long i = 0; i < e.size(); i++) {
      if (!ma.count(e[i])) {
        ma[e[i]] = ma.size();
      }
    }
    long long ans = 0;
    for (long long i = 0; i < v.size(); i++) {
      v[i] = ma[v[i]];
    }
    fill(fen, fen + n + m, 0);
    for (long long i = 0; i < v.size(); i++) {
      ans += get(v[i] + 1);
      add(v[i]);
    }
    cout << ans << '\n';
  }
}
