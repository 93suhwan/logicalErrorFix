#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a, b, _a, _b;
int ans;
int readchar() {
  char xx = 0;
  while (xx != 'l' && xx != 'r') xx = getchar();
  if (xx == 'l')
    return 0;
  else
    return 1;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    bool swp = false;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    _a = readchar(), _b = readchar();
    ans = 0;
    if (_a) swp = true, a = n - a - 1, b = n - b - 1, _a = (!_a), _b = (!_b);
    if (_b == 1) {
      int qwq = min(a, n - b - 1);
      a -= qwq, b += qwq;
      if (a == qwq) swp = true, a = n - a - 1, b = n - b - 1;
      _b = 0;
    }
    if (_b == 0) {
      if (a < b) {
        int K = b - a;
        if (K & 1)
          ans = 0;
        else
          ans = n - 1;
      } else if (a == b)
        ans = n - 1;
      else if (a > b) {
        int K = b - a;
        if (K & 1)
          ans = n - 1;
        else
          ans = 0;
      }
    }
    if (!swp)
      printf("%d\n", ans);
    else
      printf("%d\n", n - 1 - ans);
  }
  return 0;
}
