#include <bits/stdc++.h>
using namespace std;
string int_to_string(long long n) {
  string s = "";
  while (n) {
    long long now = n % 10;
    s += now + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long string_to_int(string s) {
  long long n = 0;
  for (int i = 0; i < (int)(s.size()); i++) {
    n *= 10;
    n += s[i] - '0';
  }
  return n;
}
void chmax(int &a, int b) { a = max(a, b); }
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int lcp[5050][5050];
int dp[5050];
int n;
string s;
bool check(int x, int y) {
  if (lcp[x][y] == n - x + 1) {
    return 0;
  }
  return s[x + lcp[x][y] - 1] > s[y + lcp[x][y] - 1];
}
int doit(int x, int y) {
  if (!check(x, y)) {
    return -1e9;
  }
  return n - x + 1 - lcp[x][y];
}
void solve() {
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      lcp[i][j] = 0;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (i == j) {
        lcp[i][j] = n - i + 1;
      } else {
        if (s[i - 1] == s[j - 1]) {
          lcp[i][j] = lcp[i + 1][j + 1] + 1;
        }
      }
    }
  }
  int ans = n;
  for (int i = 1; i <= n; i++) {
    dp[i] = n - i + 1;
    for (int j = 1; j <= i - 1; j++) {
      chmax(dp[i], dp[j] + doit(i, j));
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
