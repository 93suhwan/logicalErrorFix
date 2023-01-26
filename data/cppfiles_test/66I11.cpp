#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a, b, _a, _b;
int la, lb, l_a, l_b;
int ans;
int readchar() {
  char xx = 0;
  while (xx != 'l' && xx != 'r') xx = getchar();
  if (xx == 'l') {
    for (int i = 1; i <= 3; i++) xx = getchar();
    return 0;
  } else {
    for (int i = 1; i <= 4; i++) xx = getchar();
    return 1;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    bool swp = false;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    _a = readchar(), _b = readchar();
    ans = 0;
    bool rem = false;
    if (_a) swp = true, a = n - a - 1, b = n - b - 1, _a = (!_a), _b = (!_b);
    if (_b == 1) {
      if (a >= b) rem = true;
      int qwq = min(a, n - b - 1);
      a -= qwq, b += qwq;
      if (a == 0) swp = (!swp), a = n - a - 1, b = n - b - 1;
      _b = 0;
      if (rem) {
        if (abs(a - b) > 1)
          a--;
        else if (abs(a - b) == 1)
          swp = (!swp), a = 1, b = 0;
      }
    }
    if (_b == 0) {
      if (a < b) {
        int K = b - a;
        if (K & 1)
          ans = 0;
        else
          ans = n - 1;
      } else if (a == b) {
        if (a < n - 1)
          ans = n - 1;
        else
          ans = 0;
      } else if (a > b) {
        int K = a - b;
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
