#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool arr[20][20][20];
long long f = 0;
long long d = 0;
bool vis[55][55];
std::vector<pair<long long, long long>> p1, p2;
long long rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};
std::vector<long long> l(100001);
std::vector<long long> r(100001);
const long long N = 2010;
long long dp[N][N];
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (gcd(a, b)) / (a * b); }
long long lcs(string a, string b) {
  long long dp[a.size() + 1][b.size() + 1];
  long long mx = 0;
  for (long long i = 0; i <= a.size(); i++) {
    for (long long j = 0; j <= b.size(); j++) {
      dp[i][j] = 0;
    }
  }
  for (long long i = 1; i <= a.size(); i++) {
    for (long long j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        mx = max(mx, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return mx;
}
long long flg = 0;
void dfs(long long src, map<long long, vector<long long>>& adj,
         vector<long long>& visited, vector<long long>& deg) {
  if (visited[src]) {
    return;
  }
  visited[src] = 1;
  if (deg[src] != 2) {
    flg = 1;
  }
  for (auto i : adj[src]) {
    dfs(i, adj, visited, deg);
  }
}
long long mn[500001];
long long res[500001];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2 == 0) {
      cout << max((long long)15, 5 * (n / 2)) << "\n";
    } else {
      cout << max((long long)15, 5 * (n / 2 + 1)) << "\n";
    }
  }
  return 0;
}
