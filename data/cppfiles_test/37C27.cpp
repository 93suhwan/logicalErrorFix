#include <bits/stdc++.h>
using namespace std;
long long M = 998244353;
long long fpow(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long p = fpow(x, y / 2);
  p *= p;
  p %= M;
  if (y & 1) p *= x;
  return p % M;
}
vector<int> v[100005];
long long ans[100005], po[100005];
bool ok;
int dfs(int ver, int k, int par) {
  int sum = 0;
  for (int i = 0; i < v[ver].size(); i++) {
    if (v[ver][i] == par) continue;
    sum += dfs(v[ver][i], k, ver);
  }
  if (sum % k == 0) {
    return 1;
  }
  if ((sum + 1) % k != 0) ok = 0;
  return 0;
}
int main() {
  po[0] = 1;
  for (int i = 1; i < 100005; i++) {
    po[i] = 2 * po[i - 1];
    po[i] %= M;
  }
  int t, x, y, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    ans[1] = po[n - 1];
    for (int k = 2; k <= n; k++) {
      ok = 1;
      ans[k] = 0;
      if ((n - 1) % k != 0) continue;
      dfs(1, k, -1);
      ans[k] = ok;
    }
    for (int k = n; k >= 1; k--) {
      for (int i = k * 2; i <= n; i += k) {
        ans[k] = (ans[k] - ans[i] + M) % M;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
      v[i].clear();
    }
    cout << endl;
  }
  return 0;
}
