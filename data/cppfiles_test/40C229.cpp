#include <bits/stdc++.h>
using namespace std;
long long fact[1000001] = {0};
void preFact() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 1000001; i++) {
    fact[i] = (fact[i - 1] * (i % 1000000007)) % 1000000007;
  }
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long setBitNumber(long long n) {
  if (n == 0) return 0;
  long long msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }
  return (msb);
}
long long binaryExpon(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= (a);
      ans = ans;
    }
    a *= (a);
    a = a;
    b = b >> 1;
  }
  return ans;
}
long long nCr(long long n, long long r) {
  if (n < r) {
    return 0;
  } else {
    long long ans = fact[n];
    ans = ans * (binaryExpon(fact[r], (1000000007 - 2)) % 1000000007) %
          1000000007;
    ans = ans * (binaryExpon(fact[n - r], (1000000007 - 2)) % 1000000007) %
          1000000007;
    return ans;
  }
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
vector<long long> dijkstra(long long src, vector<vector<long long>> edges[],
                           long long n) {
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      q;
  vector<long long> dist(n + 1, LLONG_MAX);
  dist[src] = 0;
  q.push({src, 0});
  long long node, d;
  while (!q.empty()) {
    node = q.top().first;
    d = q.top().second;
    q.pop();
    if (d != dist[node]) {
      continue;
    }
    for (auto edge : edges[node]) {
      if (dist[node] + edge[1] < dist[edge[0]]) {
        dist[edge[0]] = dist[node] + edge[1];
        q.push({edge[0], dist[edge[0]]});
      }
    }
  }
  return dist;
}
long long inf = 1e18;
void solve() {
  long long m;
  cin >> m;
  ;
  vector<vector<long long>> mat(2, vector<long long>(m, 0));
  vector<vector<long long>> vis(2, vector<long long>(m, 0));
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  if (m == 1) {
    cout << 0 << "\n";
    return;
    ;
  }
  long long dp[2][m];
  dp[0][0] = mat[0][0];
  dp[1][0] = mat[1][0];
  for (long long i = 0; i < 2; i++) {
    for (long long j = 1; j < m; j++) {
      dp[i][j] = 0;
      dp[i][j] = mat[i][j] + dp[i][j - 1];
    }
  }
  long long ans = inf;
  for (long long j = 0; j < m; j++) {
    if (j == 0) {
      ans = ((ans > dp[0][m - 1] - dp[0][0]) ? dp[0][m - 1] - dp[0][0] : ans);
      continue;
    } else if (j == m - 1) {
      ans = ((ans > dp[1][m - 2]) ? dp[1][m - 2] : ans);
      continue;
    }
    long long p1 = 0;
    long long p2 = 0;
    p1 = dp[0][m - 1] - dp[0][j];
    p2 = dp[1][j - 1];
    ans = ((ans > ((p1 > p2) ? p1 : p2)) ? ((p1 > p2) ? p1 : p2) : ans);
  }
  cout << ans << "\n";
  return;
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  ;
  while (t--) {
    solve();
  };
}
