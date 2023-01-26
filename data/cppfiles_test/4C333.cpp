#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int main() {
  t = read();
  while (t--) {
    n = read();
    int flag = 0;
    a = b = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (n % j == i) {
          if (!a && !b) {
            a = j;
            b = (n - i) / j;
            if (a == b)
              b = 0;
            else
              flag = 1;
          } else if (a && !b)
            b = j, flag = 1;
        }
        if (flag == 1) break;
      }
      if (flag == 1)
        break;
      else
        a = b = 0;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
