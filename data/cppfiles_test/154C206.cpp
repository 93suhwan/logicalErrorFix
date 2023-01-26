#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 9, M = 1e7 + 6, mod = 998244353, OO = 0x3f3f3f3f, sqr = 320;
const long long LOO = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-7;
vector<long long> parent;
vector<set<long long>> ppr;
vector<vector<long long>> adj;
long long n, m, t, x, y, totalP;
void P();
void dfs(long long u) {
  ppr[u].insert(totalP);
  for (auto v : adj[u]) dfs(v);
}
long long findParent2(long long u) {
  ppr[u].insert(totalP);
  if (u == parent[u]) return u;
  return parent[u] = findParent2(parent[u]);
}
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  int mx = max({a, b, c});
  if (2 * mx == sum)
    cout << "YES\n";
  else if (a == b) {
    if (c % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (a == c) {
    if (b % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (c == b) {
    if (a % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int testCases = 1;
  cin >> testCases;
  while (testCases--) solve();
  return 0;
}
