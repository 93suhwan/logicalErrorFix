#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long mpow(long long base, long long exp);
void ipgraph(long long n, long long m);
void dfs(long long u, long long par);
const long long N = 100005, M = 100005;
vector<long long> g[N];
long long a[N];
void solve() {
  long long i, j, n, m, x, y, k;
  cin >> x >> y;
  if (x == y)
    cout << x << "\n";
  else if (x > y)
    cout << x + y << "\n";
  else
    cout << y - (y % x) / 2 << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
}
long long mpow(long long base, long long exp) {
  base %= ((long long)1e9 + 7);
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % ((long long)1e9 + 7);
    base = ((long long)base * base) % ((long long)1e9 + 7);
    exp >>= 1;
  }
  return result;
}
void ipgraph(long long n, long long m) {
  long long i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(long long u, long long par) {
  for (long long v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
