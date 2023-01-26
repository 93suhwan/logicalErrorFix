#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long double pi = 3.141592653589793238;
void pls() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 3e5 + 2;
int dp[(1LL << 23)];
int mul(long long a, long long b) { return (a % mod * b % mod) % mod; }
void solve() {
  {
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      vector<int> cur(26, 0);
      for (int j = 0; j < s.size(); j++) cur[(s[j] - 'a')]++;
      arr.push_back(cur);
    }
    for (int i = 0; i < (1 << n); i++) dp[i] = 0;
    for (int i = 1; i < (1 << n); i++) {
      vector<int> cur(26, INT_MAX);
      int bit = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = 0; k < 26; k++) cur[k] = min(cur[k], arr[j][k]);
          bit++;
        }
      }
      int ans = 1;
      for (int i = 0; i < 26; i++) ans = mul(ans, cur[i] + 1);
      if (bit & 1)
        dp[i] = ans;
      else
        dp[i] = -ans;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << n); j++) {
        if (j & (1 << i)) {
          { dp[j] += dp[j ^ (1 << i)]; }
        }
      }
    }
    long long res = 0;
    for (int i = 0; i < (1 << n); i++) {
      long long cur = 0;
      long long kk = 0;
      long long sum = 0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) kk++, sum += (j + 1);
      cur = dp[i] * kk * sum;
      res = res ^ cur;
    }
    cout << res << "\n";
  }
}
int main() {
  pls();
  solve();
  return 0;
}
