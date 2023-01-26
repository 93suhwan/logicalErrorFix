#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const long long N = 5e3 + 5;
string s;
long long n, Next[N][N], Dp[N];
void Input() {
  cin >> n >> s;
  s = ' ' + s;
}
void Solve() {
  long long Res = 0;
  for (long long i = n; i >= 1; --i) {
    for (long long j = n; j > i; --j) {
      if (s[i] != s[j])
        Next[i][j] = 0;
      else
        Next[i][j] = Next[i + 1][j + 1] + 1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    Dp[i] = n - i + 1;
    for (long long j = i - 1; j >= 1; --j) {
      if (i + Next[j][i] > n) continue;
      long long Pos = i + Next[j][i];
      char C1 = s[i + Next[j][i]], C2 = s[j + Next[j][i]];
      if (C1 > C2) {
        Dp[i] = max(Dp[i], Dp[j] + n - Pos + 1);
      }
    }
    Res = max(Res, Dp[i]);
  }
  cout << Res << '\n';
}
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Test;
  cin >> Test;
  while (Test--) {
    Input();
    Solve();
  }
}
