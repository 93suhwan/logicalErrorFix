#include <bits/stdc++.h>
#pragma GCC optimize "O3"
using namespace std;
const int INF = 1e9 + 7;
const int mod = 31607;
const int N = 1e6 + 7;
const int T = 1 << 20;
long long sil[N];
long long odw[N];
long long fast(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % INF;
    a = a * a % INF;
    b /= 2;
  }
  return ret;
}
long long npok(long long a, long long b) {
  if (b > a or b < 0) return 0;
  return sil[a] * odw[b] % INF * odw[a - b] % INF;
}
void prep() {
  sil[0] = 1;
  for (int i = 1; i < N; i++) sil[i] = sil[i - 1] * i % INF;
  odw[N - 1] = fast(sil[N - 1], INF - 2);
  for (int i = N - 2; i >= 0; i--) odw[i] = odw[i + 1] * (i + 1) % INF;
}
vector<vector<int> > G;
int dfs(int start, int kon, int prz = -1) {
  if (start == kon) return 0;
  int ans = INF;
  for (auto& u : G[start])
    if (u != prz) ans = min(ans, dfs(u, kon, start) + 1);
  return ans;
}
int dist[1004][1004];
void solve() {
  int n, k;
  cin >> n >> k;
  G = vector<vector<int> >(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        dist[i][j] = dfs(i, j);
      }
  if (k == 2) {
    cout << n * (n - 1) / 2 << '\n';
  } else {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      vector<int> siema(n + 1);
      for (int j = 1; j <= n; j++) siema[dist[i][j]]++;
      for (auto& u : siema) ans = (ans + npok(u, k)) % INF;
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  cin >> test;
  prep();
  for (int i = 0; i < test; i++) solve();
}
