#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
long long md = 1000000007;
using namespace std;
template <typename T>
T pw(T a, T b) {
  T c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m), b /= 2;
  }
  return c;
}
template <typename T>
T ceel(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <typename T>
T my_log(T n, T b) {
  T i = 1, ans = 0;
  while (1) {
    if (i > n) {
      ans--;
      break;
    }
    if (i == n) break;
    i *= b, ans++;
  }
  return ans;
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long inverse(long long i) {
  if (i == 1) return 1;
  return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long t, n, k, x, y, h = 0;
vector<long long> adj[101], vis(101), dist(101);
long long dis[101][101];
void dfs(long long u) {
  vis[u] = 1;
  for (auto s : adj[u]) {
    if (vis[s]) continue;
    dist[s] = dist[u] + 1;
    dis[dist[s]][h]++;
    dfs(s);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (long long i = 0; i < n + 1; i++) adj[i].clear();
    for (long long i = 0; i < n - 1; i++)
      cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    if (k == 2) {
      cout << (n * (n - 1)) / 2 << "\n";
      continue;
    }
    long long ans = 0;
    for (long long i = 1; i < n + 1; i++) {
      for (long long j = 1; j < n + 1; j++) vis[j] = 0;
      if (adj[i].size() < k) continue;
      long long o = adj[i].size();
      h = 0;
      for (long long j = 0; j < n + 1; j++)
        for (long long p = 0; p < o; p++) dis[j][p] = 0;
      for (auto w : adj[i]) {
        dist[w] = 1;
        dis[1][h]++;
        for (long long p = 0; p < n + 1; p++) vis[p] = 0;
        vis[i] = 1;
        dfs(w), h++;
      }
      for (long long j = 1; j < n + 1; j++) {
        vector<long long> v;
        for (long long p = 0; p < o; p++) {
          if (dis[j][p]) v.push_back(dis[j][p]);
        }
        if (v.size() < k) continue;
        long long g = v.size();
        long long dp[g][k + 1];
        for (long long dd = 0; dd < g; dd++)
          for (long long tt = 0; tt < k + 1; tt++) dp[dd][tt] = 0;
        dp[0][0] = 1, dp[0][1] = v[0];
        ans = (ans + dp[0][k]) % md;
        for (long long dd = 1; dd < g; dd++) {
          dp[dd][0] = 1;
          for (long long tt = 1; tt < k + 1; tt++) {
            dp[dd][tt] += dp[dd - 1][tt];
            dp[dd][tt] %= md;
            dp[dd][tt] += (dp[dd - 1][tt - 1] * v[dd]) % md;
            dp[dd][tt] %= md;
          }
          ans = (ans + dp[dd][k]) % md;
        }
      }
    }
    cout << ans << "\n";
  }
}
