#include <bits/stdc++.h>
using namespace std;
void PV(vector<long long> v) {
  for (long long i = 0; i < (long long)v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
void PVV(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < (long long)v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << ' ';
  cout << "\n";
}
void IN(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
inline void op() {}
const long long M = 1e9 + 7;
const long long IM = 1e18 + 37;
const long long N = 1000 + 10;
vector<long long> v[N];
map<long long, long long> cn[N];
long long mx = 0;
void dfs(long long x, long long baap, long long col, long long l) {
  mx = max(mx, l);
  cn[col][l]++;
  for (long long it : v[x]) {
    if (it != baap) dfs(it, x, col, l + 1);
  }
}
long long dp[N][N];
long long solve(long long l, long long k, long long d) {
  if (l == 0) return (k == 0);
  if (dp[l][k] != -1) return dp[l][k];
  long long ans = 0;
  ans = solve(l - 1, k, d) % M;
  ans = (ans + (solve(l - 1, k - 1, d) * cn[l][d]) % M) % M;
  return dp[l][k] = ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  op();
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i <= n; i++) {
      v[i].clear();
    }
    for (long long i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    long long ans = 0;
    if (k == 2) {
      ans = (n * (n - 1) / 2) % M;
      cout << (ans) << "\n";
      continue;
    }
    for (long long i = 1; i <= n; i++) {
      mx = 0;
      long long col = 1;
      for (long long it : v[i]) {
        dfs(it, i, col++, 1);
      }
      for (long long i = 1; i <= mx; i++) {
        for (long long j = 0; j <= col; j++) fill(dp[j], dp[j] + k + 10, -1);
        ans = (ans + solve(col, k, i)) % M;
      }
      for (long long j = 1; j <= col; j++) cn[j].clear();
    }
    cout << (ans) << "\n";
  }
  return 0;
}
