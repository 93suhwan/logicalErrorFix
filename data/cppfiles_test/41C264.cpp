#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long MOD = long long(9e18)) {
  long long res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
    a %= MOD;
    res %= MOD;
  }
  return res % MOD;
}
template <typename T>
void umax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void umin(T& a, T b) {
  a = min(a, b);
}
clock_t startTime;
double getTime() { return (double)(clock() - startTime) / CLOCKS_PER_SEC; }
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  for (auto el : v) {
    s << el << ' ';
  }
  return s;
}
long long mod = 998244353;
int T = 1;
int n, q;
string s;
long long dp[3][3][3][200010];
void solve() {
  cin >> n >> q;
  cin >> s;
  for (int c1 = (0); c1 < (3); c1++) {
    for (int c2 = (0); c2 < (3); c2++) {
      for (int c3 = (0); c3 < (3); c3++) {
        if (c1 == c2 || c2 == c3 || c1 == c3) {
          continue;
        }
        char d[3] = {char(c1 + 'a'), char(c2 + 'a'), char(c3 + 'a')};
        for (int i = (0); i < (n); i++) {
          char cur = d[i % 3];
          if (s[i] != cur) dp[c1][c2][c3][i]++;
          if (i) dp[c1][c2][c3][i] += dp[c1][c2][c3][i - 1];
        }
      }
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    long long ans = long long(9e18);
    for (int c1 = (0); c1 < (3); c1++) {
      for (int c2 = (0); c2 < (3); c2++) {
        for (int c3 = (0); c3 < (3); c3++) {
          if (c1 == c2 || c2 == c3 || c1 == c3) {
            continue;
          }
          long long curAns =
              dp[c1][c2][c3][r] - (l ? dp[c1][c2][c3][l - 1] : 0);
          umin(ans, curAns);
        }
      }
    }
    cout << ans << "\n";
  }
  return;
}
int main() {
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (T--) {
    solve();
    cout << "\n";
    cout.flush();
  };
  return 0;
}
