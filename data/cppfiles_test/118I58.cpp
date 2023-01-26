#include <bits/stdc++.h>
using namespace std;
const int maxn = 250007;
vector<vector<int>> adj;
vector<int> childrencounts;
vector<long long> fact(maxn);
vector<long long> invfact(maxn);
const long long MOD = 998244353;
void dfs(int v, int p) {
  int children = 0;
  for (int u : adj[v]) {
    if (u != p) {
      dfs(u, v);
      children++;
    }
  }
  childrencounts[children]++;
}
long long binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (invfact[k] * invfact[n - k] % MOD) % MOD;
}
long long expmod(long long a, long long b, int m) {
  int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i * fact[i - 1] % MOD;
  }
  invfact[maxn - 1] = expmod(fact[maxn - 1], MOD - 2, MOD);
  for (int i = maxn - 1; i >= 1; i--) {
    invfact[i - 1] = i * invfact[i] % MOD;
  }
  int n;
  cin >> n;
  adj.resize(n);
  childrencounts.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, 0);
  vector<long long> poly(n + 1);
  poly[0] = 1;
  int deg = 0;
  vector<pair<int, int>> factors;
  for (int c = 1; c < n; c++) {
    if (childrencounts[c]) {
      factors.push_back({childrencounts[c], c});
    }
  }
  sort(factors.begin(), factors.end(), less<pair<int, int>>());
  for (pair<int, int> x : factors) {
    int k = x.first;
    int c = x.second;
    for (int i = deg + k; i >= 1; i--) {
      long long b = c;
      for (int j = max(1, i - deg - 1); j <= min(i, k); j++) {
        poly[i] += (b * binommod(k, j) % MOD) * poly[i - j] % MOD;
        poly[i] %= MOD;
        b = (b * c) % MOD;
      }
    }
    deg += k;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += fact[n - i] * (i & 1 ? -1 : 1) * poly[i] % MOD;
    ans %= MOD;
  }
  cout << (ans + MOD) % MOD << endl;
}
