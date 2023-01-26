#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
bool dfs(vector<int> adj[], int p, int c, int a[], int k, bool &isposs) {
  a[c] = 0;
  for (auto u : adj[c])
    if (u != p) {
      bool f = dfs(adj, c, u, a, k, isposs);
      if (!f) {
        a[c]++;
      }
    }
  if (a[c] % k && p != -1) {
    a[c]++;
    if (a[c] % k) {
      isposs = false;
    }
    return true;
  }
  if (p == -1 && a[c] % k) {
    isposs = false;
  }
  return false;
}
long long fastexp(long long n, long long k) {
  if (k == 0)
    return 1;
  else if (k % 2)
    return (fastexp(n, k - 1) * n) % mod;
  else {
    long long w = fastexp(n, k / 2);
    return (w * w) % mod;
  }
}
vector<int> facts[100001];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i <= 100000; i++) {
    for (int j = 2 * i; j <= 100000; j += i) {
      facts[j].push_back(i);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> adj[n];
    int a[n];
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
      ans[i] = 0;
    }
    ans[1] = fastexp(2, n - 1);
    for (auto f : facts[n - 1]) {
      bool ths = true;
      dfs(adj, -1, 0, a, f, ths);
      ans[f] = ths;
    }
    if (n != 2) {
      bool ths = true;
      dfs(adj, -1, 0, a, n - 1, ths);
      ans[n - 1] = ths;
    }
    for (int j = n - 1; j >= 2; j--) {
      if (ans[j]) {
        for (auto f : facts[j]) {
          ans[f] -= ans[j];
        }
        ans[1] -= ans[j];
      }
    }
    ans[1] += mod;
    ans[1] %= mod;
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
