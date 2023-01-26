#include <bits/stdc++.h>
using namespace std;
vector<long long int> Tree;
void make_Tree(vector<long long int> &v) {
  long long int i;
  long long int N = v.size();
  while (N & (N - 1)) N++;
  v.resize(N);
  Tree.resize(2 * N);
  for (i = 0; i < N; i++) {
    Tree[N + i] = v[i];
  }
  for (i = N - 1; i >= 1; i--) {
    Tree[i] = Tree[2 * i] + Tree[2 * i + 1];
  }
}
long long int segment(long long int node, long long int node_left,
                      long long int node_right, long long int query_left,
                      long long int query_right) {
  if (query_left <= node_left && node_right <= query_right) {
    return Tree[node];
  }
  if (query_right < node_left || node_right < query_left) {
    return 0;
  }
  long long int last_left = (node_left + node_right) / 2;
  return segment(2 * node, node_left, last_left, query_left, query_right) +
         segment(2 * node + 1, last_left + 1, node_right, query_left,
                 query_right);
}
void update_Tree(long long int Index, long long int Val) {
  long long int N = Tree.size() / 2;
  long long int Diff = Val - Tree[N + Index - 1];
  for (long long int i = N + Index - 1; i >= 1; i /= 2) {
    Tree[i] += Diff;
  }
}
const long long int maxN = 100001;
vector<long long int> inF(maxN), F(maxN), isPrime(maxN), Ad[maxN];
map<long long int, long long int> Vis;
void dfs(long long int node) {
  if (Vis[node]) return;
  Vis[node] = 1;
  for (auto child : Ad[node]) {
    dfs(child);
  }
  return;
}
long long int pow1(long long int n, long long int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  long long int X = 1;
  if (k % 2 == 1) X = n % 1000000007;
  long long int Y = pow1(n, k / 2) % 1000000007;
  return (((Y * Y) % 1000000007) * X) % 1000000007;
}
void fact_compute() {
  long long int N = maxN - 1;
  F[0] = 1;
  F[1] = 1;
  for (long long int i = 2; i <= N; i++) {
    F[i] = (F[i - 1] * (i)) % 1000000007;
  }
  inF[N] = pow1(F[N], 1000000007 - 2) % 1000000007;
  for (long long int i = N - 1; i >= 0; i--) {
    inF[i] = (inF[i + 1] * (i + 1)) % 1000000007;
  }
}
void sieve() {
  for (long long int i = 2; i < maxN; i++) {
    isPrime[i] = 1;
  }
  for (long long int i = 2; i < maxN; i++) {
    for (long long int j = 2 * i; j < maxN; j += i) {
      isPrime[j] = 0;
    }
  }
}
long long int gcd(long long int n, long long int m) {
  if (!m) return n;
  return gcd(m, n % m);
}
long long int lcm(long long int n, long long int m) {
  return (n / gcd(n, m)) * m;
}
void set_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
void solve() {
  long long int n, m, j, k, l, i;
  cin >> n >> k;
  vector<long long int> v(n);
  long long int isOne = 0;
  vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, -1));
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 1) {
      isOne = 1;
    }
  }
  if (!isOne) {
    cout << -1;
    cout << "\n";
    return;
  }
  long long int ans = n;
  long long int maxi = 1;
  for (i = 0; i < n; i++) {
    long long int val = v[i];
    if (i != 0) {
      if (v[i] == 1) {
        dp[i][1] = 1;
      }
      for (j = 0; j < i; j++) {
        if (v[i] > v[j]) {
          if (i - j >= v[i] - v[j] && dp[j][v[j]] != -1) {
            dp[i][v[i]] = max(dp[i][v[i]], dp[j][v[j]] + 1);
          }
        }
      }
    } else {
      if (v[i] == 1) {
        dp[i][1] = 1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 1; j <= n; j++) {
      if (dp[i][j] >= k) {
        ans = min(ans, i + 1 - j);
      }
    }
  }
  cout << ans;
  cout << "\n";
  return;
}
int main() {
  set_io();
  long long int totalTestCase = 1;
  cin >> totalTestCase;
  for (long long int testCase = 1; testCase <= totalTestCase; testCase++) {
    solve();
  }
  return 0;
}
