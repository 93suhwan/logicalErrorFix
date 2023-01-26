#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const int oo = 1e9;
const long long OO = 1e17;
const long long MOD = 1e9 + 7;
int start = 0;
template <class T>
void input1(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) cin >> x[i];
}
template <class T>
void input2(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) input1(x[i]);
}
template <class T>
void print1(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) cout << x[i] << ' ';
  cout << '\n';
}
template <class T>
void print2(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) print1(x[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long> p(2e5 + 1);
  p[0] = 1;
  for (int i = int(1); i <= int(2e5); ++i) p[i] = p[i - 1] * 2, p[i] %= MOD;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << '\n';
      continue;
    }
    vector<vector<long long> > dp(k + 1, vector<long long>(2));
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = p[n - 1] - (n & 1);
    dp[1][1] = p[n - 1] + (n & 1);
    for (int i = int(2); i <= int(k); ++i) {
      if (n & 1) {
        dp[i][0] += dp[i - 1][0] * p[n];
        dp[i][0] %= MOD;
        dp[i][0] += dp[i - 1][1] * (p[n - 1] - 1);
        dp[i][0] %= MOD;
        dp[i][1] += dp[i - 1][1] * (p[n - 1] + 1);
        dp[i][1] %= MOD;
      } else {
        dp[i][0] += dp[i - 1][0] * (p[n] - 1);
        dp[i][0] %= MOD;
        dp[i][0] += dp[i - 1][1] * p[n - 1];
        dp[i][0] %= MOD;
        dp[i][1] += dp[i - 1][0];
        dp[i][1] %= MOD;
        dp[i][1] += dp[i - 1][1] * p[n - 1];
        dp[i][1] %= MOD;
      }
    }
    cout << dp[k][1] << '\n';
  }
}
