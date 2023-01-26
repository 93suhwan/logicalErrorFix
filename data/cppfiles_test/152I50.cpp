#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int T;
int N;
int P[1010101];
pair<int, int> from[1010101][2][2];
int dp[1010101][2][2];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (i = 0; i < (N); i++) scanf("%d", &P[i]);
    for (i = 0; i < (N); i++)
      dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 1LL << 30;
    dp[0][0][0] = dp[0][0][1] = -1LL << 30;
    int pos, sig, ns;
    for (i = 0; i < (N - 1); i++)
      for (pos = 0; pos < (2); pos++)
        for (sig = 0; sig < (2); sig++) {
          if (pos == 0) {
            x = (sig ? -P[i] : P[i]);
            y = dp[i][pos][sig];
          } else {
            x = dp[i][pos][sig];
            y = (sig ? -P[i] : P[i]);
          }
          for (ns = 0; ns < (2); ns++) {
            int v = ns ? -P[i + 1] : P[i + 1];
            if (v > x) {
              if (chmin(dp[i + 1][0][ns], y)) from[i + 1][0][ns] = {pos, sig};
            } else if (v > y) {
              if (chmin(dp[i + 1][1][ns], x)) from[i + 1][1][ns] = {pos, sig};
            }
          }
        }
    pos = sig = -1;
    for (x = 0; x < (2); x++)
      for (y = 0; y < (2); y++)
        if (dp[N - 1][x][y] < 1 << 30) pos = x, sig = i;
    if (pos == -1) {
      cout << "NO" << endl;
    } else {
      for (i = N - 1; i >= 0; i--) {
        if (sig) P[i] = -P[i];
        auto p = from[i + 1][pos][sig];
        pos = p.first;
        sig = p.second;
      }
      cout << "YES" << endl;
      for (i = 0; i < (N); i++) cout << P[i] << " ";
      cout << endl;
    }
  }
}
int main(int argc, char **argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
