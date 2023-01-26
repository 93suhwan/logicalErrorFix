#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int base = 998244353;
int t, n, f[N], d[N];
vector<int> a[N];
void dfs(int u, int p, int c) {
  if (f[c] == 0) return;
  d[u] = 0;
  for (auto v : a[u])
    if (v != p) dfs(v, u, c);
  if (d[u] % c == 0)
    d[p]++;
  else if ((d[u] + 1) % c != 0)
    f[c] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
    }
    f[n] = 0;
    f[1] = 1;
    for (int i = 1; i < n; i++) f[1] = (f[1] * 2) % base;
    for (int i = 2; i < n; i++)
      if ((n - 1) % i == 0) {
        f[i] = 1;
        dfs(1, 0, i);
      }
    for (int i = n - 1; i > 1; i--)
      for (int j = i * 2; j <= n - 1; j += i)
        if (f[j] > 0) {
          f[i] = 0;
          break;
        }
    for (int i = 2; i < n; i++) f[1] = (f[1] - f[i] + base) % base;
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << "\n";
  }
  return 0;
}
