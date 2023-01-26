#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const long long int INF = 1e15;
const long long int MOD = 1e9 + 7;
long long int rootn(long long int x, long long int y) {
  return ceil(log(x) / log(y));
}
bool sortbysec(pair<long long int, long long int> &a,
               pair<long long int, long long int> &b) {
  return a.second < b.second;
}
bool sortbyfirstdesc(pair<long long int, long long int> &a,
                     pair<long long int, long long int> &b) {
  return a.first > b.first;
}
bool sortbysecdesc(pair<long long int, long long int> &a,
                   pair<long long int, long long int> &b) {
  return a.second > b.second;
}
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long int inversemod(long long int n, long long int mod) {
  return power(n, mod - 2) % MOD;
}
const long long int maxl = 2e5 + 5;
bool isprime[maxl];
long long int fact[maxl];
void sieve() {
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i * i < maxl; i++) {
    if (isprime[i]) {
      for (long long int j = i * i; j < maxl; j += i) isprime[j] = false;
    }
  }
}
void inifact() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long int i = 2; i < maxl; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= MOD;
  }
}
long long int dfs(long long int vert, vector<long long int> &vis,
                  vector<long long int> v[]) {
  vis[vert] = true;
  long long int locans = 0;
  for (auto xx : v[vert]) {
    if (!vis[xx]) {
      locans += dfs(xx, vis, v);
    }
  }
  return locans + 1;
}
vector<long long int> binary(long long int n) {
  vector<long long int> res;
  while (n > 0) {
    res.push_back(n % 2);
    n /= 2;
  }
  while (res.size() < 4) {
    res.push_back(0);
  }
  reverse(res.begin(), res.end());
  return res;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int mat[n][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) cin >> mat[i][j];
  }
  vector<long long int> v[n * m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      vector<long long int> loc = binary(mat[i][j]);
      if (loc[0] == 0) {
        v[i * m + j].push_back((i - 1) * m + j);
      }
      if (loc[1] == 0) {
        v[i * m + j].push_back(i * m + j + 1);
      }
      if (loc[2] == 0) {
        v[i * m + j].push_back((i + 1) * m + j);
      }
      if (loc[3] == 0) {
        v[i * m + j].push_back(i * m + j - 1);
      }
    }
  }
  vector<long long int> vis(n * m, false);
  vector<long long int> ans;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      long long int vt = i * m + j;
      if (!vis[vt]) {
        ans.push_back(dfs(vt, vis, v));
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<long long int>());
  for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long int t = 1;
  while (t--) solve();
}
