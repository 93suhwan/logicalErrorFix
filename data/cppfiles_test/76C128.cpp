#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const int MOD = 1000000007;
const long long MOD2 = 998244353;
const char nl = '\n';
int modulo(int n, int M) { return ((n % M) + M) % M; }
template <class T>
void print1D(T& a) {
  for (int j = 0; j < a.size(); j++) {
    cout << a[j] << " ";
  }
  cout << endl;
}
template <class T>
void print2D(T& a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
int mul(long long a, long long b, long long mod) { return (a * b) % mod; }
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  int dp_sum = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp_sum;
    for (int j = 1; j * j <= i; j++) {
      dp[i] = (dp[i] + mul(dp[j], (i / j) - (i / (j + 1)), m)) % m;
      if (j != i / j and j > 1) {
        dp[i] = (dp[i] + dp[i / j]) % m;
      }
    }
    dp_sum = (dp_sum + dp[i]) % m;
  }
  cout << dp[n] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
