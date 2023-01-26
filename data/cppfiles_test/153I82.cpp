#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
long double pi = 3.141592653589793238;
void pls() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 3e5 + 2;
int dp[(1LL << 23)][23];
int mul(int a, int b) { return (a % mod * b % mod) % mod; }
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
    for (int i = 0; i < (1LL << n); i++)
      for (int j = 0; j < n; j++) dp[i][j] = 0;
    for (int i = 1; i < (1LL << n); i++) {
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
      dp[i][bit] = ans;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1LL << n); j++) {
        if (j & (1 << i)) {
          for (int sz = 1; sz <= n; sz++) {
            dp[j][sz] += dp[j ^ (1 << i)][sz];
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < (1LL << n); i++) {
      int cur = 0;
      int kk = 0;
      int sum = 0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) kk++, sum += (j + 1);
      for (int sz = 1; sz <= n; sz++) {
        if (sz & 1)
          cur = (cur % mod + dp[i][sz] % mod) % mod;
        else {
          cur = (cur % mod - dp[i][sz] % mod) % mod;
          cur = (cur + mod) % mod;
        }
      }
      cur = cur * kk * sum;
      res = res ^ cur;
    }
    cout << res << endl;
  }
}
int main() {
  pls();
  solve();
  return 0;
}
