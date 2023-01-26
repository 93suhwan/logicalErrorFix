#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int f[300001];
int pow(int n, int i) {
  int a = n, ans = 1;
  while (i > 0) {
    if (i & 1) {
      ans = (ans * 1LL * a) % MOD;
    }
    a = (a * 1LL * a) % MOD;
    i = i >> 1;
  }
  return ans;
}
void dfs_visit(map<string, vector<string>> adj, map<string, int>& col,
               string s) {
  col[s] = 1;
  for (auto u : adj[s]) {
    if (col[u] == 0) {
      dfs_visit(adj, col, u);
    }
  }
}
int dfs_helper(map<string, vector<string>> adj, map<string, int>& col) {
  int conn = 0;
  for (auto u : adj) {
    if (col[u.first] == 0) {
      conn++;
      dfs_visit(adj, col, u.first);
    }
  }
  return conn;
}
int inv(int n) { return pow(n, MOD - 2); }
int nCr(int n, int r) {
  if (r > n)
    return 0;
  else {
    int res = f[n];
    res = (res * 1LL * inv(f[r])) % MOD;
    res = (res * 1LL * inv(f[n - r])) % MOD;
    return res;
  }
}
bool exists(string s, string b) {
  int n = s.length(), t = b.length();
  if (t > n) return false;
  for (int i = 0; i < (int)(n - t + 1); ++i) {
    if (s.substr(i, t) == b) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  string s, t, a, b = "";
  cin >> q;
  while (q--) {
    cin >> s >> t;
    int n = t.length();
    int f = 0;
    for (int i = 0; i < (int)(n); ++i) {
      a = t.substr(i + 1, min(i, n - 1 - i));
      reverse((a).begin(), (a).end());
      if (t.substr(i - min(i, n - 1 - i), a.length()) == a) {
        b = i < n - 1 - i ? t.substr(2 * i + 1) : "";
        reverse((b).begin(), (b).end());
        b += t.substr(0, i + 1);
        if (exists(s, b)) {
          cout << "YES"
               << "\n";
          f = 1;
          break;
        }
      }
    }
    if (f == 0)
      cout << "NO"
           << "\n";
  }
}
