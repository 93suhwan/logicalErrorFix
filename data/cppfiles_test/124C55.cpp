#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  cin >> t;
  precalc();
  int test_num = 1;
  while (t--) {
    solve(true);
  }
  cout.flush();
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
template <typename T>
void make_unique(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}
template <typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}
mt19937 rng(
    (unsigned long long)chrono::steady_clock::now().time_since_epoch().count());
void precalc() {}
const li mod = 1000000007;
void add(li& cur, li val) { cur = (cur + val) % mod; }
void solve(__attribute__((unused)) bool read) {
  li n;
  cin >> n;
  vector<string> s(2);
  for (li i = 0; i < 2; ++i) {
    cin >> s[i];
    for (li j = 1; j < s[i].length(); j += 2) {
      if (s[i][j] != '?') {
        s[i][j] = "10"[s[i][j] - '0'];
      }
    }
  }
  vector<vector<vector<li>>> dp(n + 1,
                                vector<vector<li>>(n + 1, vector<li>(2, 0)));
  auto cnt = dp;
  cnt[0][0][0] = 1;
  for (li i = 0; i < n; ++i) {
    for (li j = 0; j <= n; ++j) {
      if (s[0][i] != '0') {
        add(dp[i][j][1], dp[i][j][0]);
        add(cnt[i][j][1], cnt[i][j][0]);
      }
      if (j < n && s[1][j] != '0') {
        add(cnt[i + 1][j + 1][0], cnt[i][j][1]);
        add(dp[i + 1][j + 1][0], dp[i][j][1] + abs(i - j) * cnt[i][j][1]);
      }
      if (s[0][i] != '1') {
        add(cnt[i + 1][j][0], cnt[i][j][0]);
        add(dp[i + 1][j][0], dp[i][j][0]);
      }
      if (j < n && s[1][j] != '1') {
        add(cnt[i][j + 1][1], cnt[i][j][1]);
        add(dp[i][j + 1][1], dp[i][j][1]);
      }
    }
  }
  li res = 0;
  for (li i = n; i >= 0; --i) {
    if (i < n && s[1][i] == '1') {
      break;
    }
    add(res, dp[n][i][0]);
  }
  cout << res << "\n";
}
