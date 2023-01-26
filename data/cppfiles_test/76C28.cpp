#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x, long long y, long long p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, long long p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, long long r,
                                 long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void binary_Search(long long n, long long x_position, long long &cnt_big,
                   long long &cnt_less) {
  long long left = 0, right = n;
  while (left < right) {
    long long middle = (left + right) / 2;
    if (x_position >= middle) {
      if (x_position != middle) cnt_less++;
      left = middle + 1;
    } else if (x_position < middle) {
      cnt_big++;
      right = middle;
    }
  }
}
long long val = 1;
void dfs(long long root, vector<vector<long long>> &adj,
         vector<long long> &visit, set<long long> &st) {
  visit[root] = 1;
  st.insert(root);
  for (long long i = 0; i < adj[root].size(); i++) {
    if (visit[adj[root][i]] == 0) {
      dfs(adj[root][i], adj, visit, st);
    }
  }
}
void bfs_prll(vector<vector<long long>> adj, long long root,
              vector<long long> &visit) {
  visit[root] = 1;
  queue<long long> qu;
  qu.push(root);
  while (!qu.empty()) {
    long long current = qu.front();
    qu.pop();
    for (long long i = 0; i < adj[current].size(); i++) {
      if (!visit[adj[current][i]]) {
        visit[adj[current][i]] = visit[current] + 1;
        qu.push(adj[current][i]);
      }
    }
  }
}
long long mul(long long a, long long b, long long mod) { return (a * b) % mod; }
void solve() {
  long long n, m;
  cin >> n >> m;
  long long dp[n + 1];
  dp[1] = 1;
  long long sum = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = sum;
    for (long long j = 1; j * j <= i; j++) {
      dp[i] = dp[i] + mul(dp[j], (i / j - i / (j + 1)), m);
      dp[i] %= m;
      if (j != i / j and j > 1) {
        dp[i] = dp[i] + dp[i / j];
        dp[i] %= m;
      }
    }
    sum = sum + dp[i];
    sum %= m;
  }
  cout << dp[n];
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
