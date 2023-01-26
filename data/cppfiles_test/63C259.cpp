#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 1e3 + 5, mod = 1e9 + 7;
template <typename T>
bool chmin(T& a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <typename T>
bool chmax(T& a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (long long i = (0); i < (long long)(v.size()); ++i) cout << v[i] << ' ';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (typename set<T>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << ' ';
  return os;
}
void init() {}
long long p[N];
set<long long> s[N];
bool st[N];
long long find(long long x) { return x == p[x] ? x : p[x] = find(p[x]); }
void solve() {
  long long n = read(), m1 = read(), m2 = read();
  for (long long i = (1); i <= (long long)(n * 2); ++i) p[i] = i;
  while (m1--) {
    long long u = read(), v = read();
    u = find(u), v = find(v);
    for (long long x : s[u]) s[v].insert(x);
    s[u].clear();
    p[u] = v;
  }
  while (m2--) {
    long long u = read(), v = read();
    u += n, v += n;
    u = find(u), v = find(v);
    for (long long x : s[u]) s[v].insert(x);
    s[u].clear();
    p[u] = v;
  }
  vector<pair<long long, long long>> ans;
  set<long long> ot;
  for (long long x : s[find(1)]) st[x] = 1;
  for (long long i = (1); i <= (long long)(n); ++i)
    if (!st[i]) ot.insert(i);
  memset(st, 0, sizeof st);
  for (long long i = (1); i <= (long long)(n); ++i) {
    if (st[find(i)]) continue;
    st[find(i)] = 1;
    for (long long j : ot) {
      long long t1 = find(i), t2 = find(j), t3 = find(i + n), t4 = find(j + n);
      if (t1 != t2 && t3 != t4) {
        ans.push_back({i, j});
        p[t2] = t1;
        for (long long x : s[t2]) {
          s[t1].insert(x);
          auto p = ot.lower_bound(x);
          if (p != ot.end()) ot.erase(p);
        }
        s[t2].clear();
        p[t4] = t3;
        for (long long x : s[t4]) s[t3].insert(x);
        s[t4].clear();
      }
    }
  }
  cout << ans.size() << endl;
  for (long long i = (0); i <= (long long)((long long)ans.size() - 1); ++i)
    cout << ans[i].first << ' ' << ans[i].second << endl;
}
signed main() {
  long long Case = 1;
  init();
  while (Case--) solve();
  return 0;
}
