#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
template <class T>
ostream &operator<<(ostream &out, vector<T> A) {
  for (auto I : A) out << I << " ";
  return out;
}
const int N = 510;
int dp[N][N][N];
char t[N], s[N];
void upd(int &a, int b) { a = min(a, b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  cin >> s + 1 >> t + 1;
  int border = 0;
  for (int i = 1; i < m; i++) {
    bool ok = 1;
    for (int j = 1, k = m - i + 1; j <= i; j++, k++) {
      if (t[j] != t[k]) ok = 0;
    }
    if (ok) border = i;
  }
  55;
  vector<int> fail(m + 1);
  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= i; j++) {
      bool ok = 1;
      for (int x = 1, y = i - j; x < j; x++, y++)
        if (t[x] != t[y]) ok = 0;
      if (t[j] == t[i + 1]) ok = 0;
      if (ok) fail[i] = j;
    }
  }
  const int M = n - m + 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= M; j++)
      for (int k = 0; k <= m; k++) dp[i][j][k] = 1000;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= M; j++)
      for (int k = 0; k < m; k++)
        if (dp[i][j][k] != 1000) {
          if (k + 1 == m) {
            upd(dp[i + 1][j + 1][border], dp[i][j][k] + (s[i + 1] != t[k + 1]));
          } else {
            upd(dp[i + 1][j][k + 1], dp[i][j][k] + (s[i + 1] != t[k + 1]));
          }
          upd(dp[i + 1][j][fail[k]], dp[i][j][k] + (s[i + 1] == t[k + 1]));
        }
  for (int j = 0; j <= M; j++) {
    int res = 1000;
    for (int k = 0; k < m; k++) res = min(res, dp[n][j][k]);
    if (res == 1000)
      cout << -1 << "\n";
    else
      cout << res << "\n";
  }
  return 0;
}
