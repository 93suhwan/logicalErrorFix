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
int modulomult(long long a, long long b, long long m) {
  return int((a * b) % m);
}
long long solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  int dp_sum = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i] + dp_sum) % m;
    for (int x = 1; x * x <= i; x++) {
      dp[i] = (dp[i] + modulomult(dp[x], i / x - i / (x + 1), m)) % m;
      if (x != i / x && x > 1) {
        dp[i] = (dp[i] + dp[1 / x]) % m;
      }
    }
    dp_sum = (dp_sum + dp[i]) % m;
  }
  return dp[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    cout << solve() << endl;
  }
}
