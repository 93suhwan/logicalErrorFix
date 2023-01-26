#include <bits/stdc++.h>
using namespace std;
inline void R(int &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar();
  }
  x *= f;
}
string s[1000005];
int q, n, m, sum[1000005];
int main() {
  R(n), R(m);
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < m; j++)
      if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') sum[j] = 1;
  for (int i = 1; i < m; i++) sum[i] += sum[i - 1];
  R(q);
  while (q--) {
    int x, y;
    R(x), R(y);
    x--;
    y--;
    cout << ((sum[y] - sum[x]) ? "NO" : "YES") << '\n';
  }
  return 0;
}
