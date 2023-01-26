#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<int> v[110];
ll C[110][110];
int f[110];
void dfs(int u, int fa = -1, int deep = 1) {
  for (auto t : v[u]) {
    if (t == fa) continue;
    f[deep]++;
    dfs(t, u, deep + 1);
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i <= 100; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  while (t--) {
    ll ans = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    if (k == 2) {
      printf("%lld\n", C[n][2]);
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) f[j] = 0;
      dfs(i);
      for (int j = 1; j <= n; j++) {
        ans = (ans + C[f[j]][k]) % MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
