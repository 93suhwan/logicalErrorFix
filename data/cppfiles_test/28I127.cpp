#include <bits/stdc++.h>
using namespace std;
int i, j, p, q, n, m, k, t, a[300006], b[300006], br, br1;
vector<int> v[300006];
int vuz[10];
vector<int> ans;
bool f[300006];
int sh[300006];
void dfs(int u) {
  f[u] = 1;
  br1++;
  for (auto &ii : v[u]) {
    if (!f[ii]) dfs(ii);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    fill(b, b + n + 1, 0);
    fill(sh + 1, sh + n + 1, 0);
    ans.clear();
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] <= i)
        p = i - a[i];
      else
        p = n - a[i] + i;
      sh[i] = p;
      b[p]++;
    }
    q = 0;
    for (i = 0; i < n; i++) {
      if (b[i] >= n - 2 * m) {
        q++;
        vuz[q] = i;
      }
    }
    for (i = 1; i <= q; i++) {
      p = vuz[i];
      int sw = 0;
      br = 0;
      fill(f + 1, f + n + 1, 0);
      for (j = 1; j <= n; j++) {
        if (sh[j] != p) {
          k = p - sh[j];
          k = j + k;
          k %= n;
          if (k == 0) k = n;
          while (k < 0) k += n;
          v[j].push_back(k);
        }
      }
      for (j = 1; j <= n; j++) {
        br1 = 0;
        if (b[j] != p && f[j] == 0) {
          dfs(j);
          if (br1 > 0) br += br1 - 1;
        }
      }
      for (j = 1; j <= n; j++) v[j].clear();
      if (br <= m) {
        ans.push_back(vuz[i]);
      }
    }
    cout << ans.size() << " ";
    for (auto i : ans) cout << i << " ";
    cout << '\n';
  }
  return 0;
}
