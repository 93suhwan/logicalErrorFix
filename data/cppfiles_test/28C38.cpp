#include <bits/stdc++.h>
using namespace std;
long long i, j, p, q, n, m, k, t, a[300006], b[300006], br, br1;
vector<long long> v[300006];
long long vuz[10];
vector<long long> ans;
bool f[300006];
long long sh[300006];
void dfs(long long u) {
  f[u] = 1;
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
    ans.clear();
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] <= i)
        p = i - a[i];
      else
        p = n - a[i] + i;
      p %= n;
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
      long long sw = 0;
      br = 0;
      fill(f + 1, f + n + 1, 0);
      for (j = 1; j <= n; j++) {
        if (sh[j] != p) {
          k = p - sh[j];
          k = j + k;
          k %= n;
          if (k == 0) k = n;
          while (k <= 0) k += n;
          v[j].push_back(k);
        }
      }
      for (j = 1; j <= n; j++) {
        if (f[j] == 0) {
          dfs(j);
          br++;
        }
      }
      for (j = 1; j <= n; j++) v[j].clear();
      br = n - br;
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
