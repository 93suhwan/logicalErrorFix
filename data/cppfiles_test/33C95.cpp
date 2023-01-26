#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 13;
const int mod = 1e9 + 7;
long long n, k;
long long r[maxn], ans[maxn];
vector<long long> g[maxn];
void solve() {
  cin >> n;
  for (int i = 0; i < maxn; i++) r[i] = maxn, g[i].push_back(0);
  ans[0] = 1;
  long long x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    for (auto it : g[x]) {
      int to = it ^ x;
      ans[to] = 1;
      while (r[to] > x) {
        r[to]--;
        if (r[to] != x) g[r[to]].push_back(to);
      }
    }
    g[x] = {};
  }
  k = 0;
  for (auto it : ans) k += it;
  cout << k << endl;
  for (int i = 0; i < maxn; i++) {
    if (ans[i]) cout << i << " ";
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
