#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void solve() {
  int c, d;
  cin >> c >> d;
  int an = 0;
  if (c == 0 && d == 0)
    an = 0;
  else if (abs(c) == abs(d))
    an = 1;
  else if ((c + d) % 2 == 1)
    return puts("-1"), void();
  else
    an = 2;
  cout << an << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
