#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
char a[MAXN];
signed main() {
  int t = read();
  while (t--) {
    int n = read();
    scanf("%s", a);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] != '?') {
        ok = true;
        bool tp = a[i] == 'B' ? true : false;
        for (int j = i - 1; j >= 0; j--, tp ^= 1) {
          if (a[j + 1] == 'B')
            a[j] = 'R';
          else
            a[j] = 'B';
        }
        for (int j = i + 1; j < n; j++) {
          if (a[j] != '?') continue;
          if (a[j - 1] == 'B')
            a[j] = 'R';
          else
            a[j] = 'B';
        }
        printf("%s", a);
        putchar('\n');
        break;
      }
    }
    if (!ok) {
      bool tp = false;
      for (int i = 0; i < n; i++, tp ^= 1) {
        if (tp)
          putchar('B');
        else
          putchar('R');
      }
      putchar('\n');
      ;
    }
  }
  return 0;
}
