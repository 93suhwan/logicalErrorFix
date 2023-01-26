#include <bits/stdc++.h>
using namespace std;
int n, ans, tt, p[1005][6];
string s;
int sol(int x, int y) {
  int X = 0, Y = 0, Z = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i][x] == 1 && p[i][y] == 0)
      X++;
    else if (p[i][x] == 0 && p[i][y] == 1)
      Y++;
    else if (p[i][x] == 1 && p[i][y] == 1)
      Z++;
    else
      return 0;
  }
  if (X + Z >= n / 2 && Y + Z >= n / 2 && X + Y + Z >= n)
    return 1;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        cin >> p[i][j];
      }
    }
    for (int i = 1; i < 5; i++) {
      for (int j = i + 1; j <= 5; j++) {
        if (!ans) ans = max(sol(i, j), ans);
      }
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
