#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
}
bool isPrime(int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
bool BREAKTIME(long double v) { return 1.0 * clock() >= v * CLOCKS_PER_SEC; }
int mod = 1e9 + 7;
int inf = 1e9;
string A;
string B;
int f(string s) {
  string z;
  int ans = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    z = s[i] + z;
    if (z.size() >= B.size()) break;
    bool flag = 1;
    for (int j = 0; j < z.size(); ++j) {
      if (B[j] != z[j]) flag = 0;
    }
    if (flag) ans = max(ans, (int)z.size());
  }
  return ans;
}
int dp[2][505][505] = {};
void solve() {
  int n, m;
  cin >> n >> m;
  cin >> A;
  cin >> B;
  int K = n - m + 1;
  for (int i = 0; i < (2); ++i) {
    for (int j = 0; j < (505); ++j) {
      for (int k = 0; k < (505); ++k) {
        dp[i][j][k] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  vector<vector<int>> Go(m, vector<int>(2));
  string pref;
  for (int i = 0; i < (m); ++i) {
    string s = pref;
    s.push_back('0');
    Go[i][0] = f(s);
    s = pref;
    s.push_back('1');
    Go[i][1] = f(s);
    pref.push_back(B[i]);
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < B.size(); ++j) {
      for (int k = 0; k <= K; ++k) {
        if (j == 0 && k == 1) {
          int kaka = 1;
        }
        if (dp[0][j][k] == inf) continue;
        for (int w = 0; w <= 1; ++w) {
          int nextJ = Go[j][w];
          int nextK = k;
          if (j == (int)B.size() - 1 && B.back() == (w + '0')) {
            nextK++;
          }
          if (nextK > K) continue;
          dp[1][nextJ][nextK] =
              min(dp[1][nextJ][nextK], dp[0][j][k] + (('0' + w) != A[i]));
        }
      }
    }
    swap(dp[0], dp[1]);
    for (int j = 0; j < (505); ++j) {
      for (int k = 0; k < (505); ++k) {
        dp[1][j][k] = inf;
      }
    }
  }
  for (int k = 0; k <= K; ++k) {
    int ans = inf;
    for (int j = 0; j <= B.size(); ++j) {
      ans = min(ans, dp[0][j][k]);
    }
    if (ans == inf) ans = -1;
    cout << ans << " ";
  }
  cout << '\n';
}
int32_t main() {
  boostIO();
  int T;
  T = 1;
  while (T--) {
    solve();
  }
}
