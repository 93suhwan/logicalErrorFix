#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
int t, n, k;
long long cnt[111][111], res[111][111], ans;
vector<int> v[111];
long long ft[111], iv[111];
long long pw(long long x, long long y) {
  long long rt = 1;
  while (y) {
    if (y & 1) {
      rt *= x;
      rt %= md;
    }
    x *= x;
    x %= md;
    y >>= 1;
  }
  return rt;
}
long long C(long long x, long long y) {
  return ft[x] * iv[y] % md * iv[x - y] % md;
}
void dfs(int x, int y, int rt, int d) {
  cnt[x][d]++;
  for (int i = 0; i < v[x].size(); i++) {
    int z = v[x][i];
    if (z == y) {
      continue;
    }
    dfs(z, x, rt, d + 1);
    if (x != rt) {
      for (int j = 1; j <= n; j++) {
        cnt[x][j] += cnt[z][j];
      }
    } else {
      for (int j = 1; j <= n; j++) {
        for (int kk = k; kk >= 1; kk--) {
          res[j][kk] += res[j][kk - 1] * cnt[z][j] % md;
          res[j][kk] %= md;
        }
      }
    }
  }
}
int main() {
  ft[0] = 1;
  iv[0] = 1;
  for (int i = 1; i < 105; i++) {
    ft[i] = ft[i - 1] * i % md;
    iv[i] = pw(ft[i], md - 2);
  }
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      v[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    if (k == 2) {
      cout << C(n, 2) << endl;
      continue;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(res, 0, sizeof(res));
      for (int j = 1; j <= n; j++) {
        res[j][0] = 1;
      }
      memset(cnt, 0, sizeof(cnt));
      dfs(i, -1, i, 0);
      for (int j = 1; j <= n; j++) {
        ans += res[j][k];
        ans %= md;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
