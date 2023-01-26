#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int get() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int main() {
  T = get();
  while (T--) {
    N = get(), M = get();
    string s;
    cin >> s;
    int nowx = 0, nowy = 0, mxx = 0, mxy = 0, mnx = 0, mny = 0, x = 1, y = 1;
    for (auto i : s) {
      if (i == 'L')
        nowy--, mny = min(mny, nowy);
      else if (i == 'R')
        nowy++, mxy = max(mxy, nowy);
      else if (i == 'U')
        nowx--, mnx = min(mnx, nowx);
      else if (i == 'D')
        nowx++, mxx = max(mxx, nowx);
      if (mxx - mnx < N && mxy - mny < M)
        x = 1 - mnx, y = 1 - mny;
      else
        break;
    }
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
