#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int mx = 1e7 + 1;
vector<int> adj[101];
int lv[101];
void dfs(int st, int l, int pr) {
  lv[l]++;
  for (int x : adj[st]) {
    if (x != pr) {
      dfs(x, l + 1, st);
    }
  }
}
vector<long long int> fact(102), inv(102);
long long int mpow(long long int a, long long int x) {
  if (x == 0) return 1;
  long long int a1 = mpow(a, x / 2);
  a1 = (a1 * a1) % mod;
  if (x & 1) a1 = (a1 * a) % mod;
  return a1;
}
void pre() {
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < 102; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = mpow(fact[i], mod - 2);
  }
}
long long int C(long long int n, long long int r) {
  if (n < 0 or r < 0 or r > n) return 0;
  long long int den = (inv[n - r] * inv[r]) % mod;
  long long int ret = (fact[n] * den) % mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      adj[x - 1].push_back(y - 1);
      adj[y - 1].push_back(x - 1);
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      memset(lv, 0, sizeof(lv));
      dfs(i, 0, -1);
      for (int i = 1; i < n; i++) {
        ans += C(lv[i], k);
        ans %= mod;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
