#include <bits/stdc++.h>
using namespace std;
long long inline count(std::vector<long long> &v, vector<bool> &vis,
                       long long i, long long d) {
  if (vis[i]) return 0;
  long long ans = 0, n = (int)v.size();
  while (v[i] == 1 and ans++ < n) {
    vis[i] = true;
    i = (i + d) % n;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    std::vector<long long> v(n);
    for (auto &x : v) {
      cin >> x;
    }
    std::vector<bool> vis(n, false);
    long long ans = 0;
    for (long long i = 0; i < n; i++) ans = max(ans, count(v, vis, i, d));
    if (ans > n)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
