#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
const int maxm = 2500 + 5;
const int inf = 1 << 29;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
long long read() {
  long long s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') w = -1;
  }
  for (; isdigit(c); c = getchar()) {
    s = (s << 3) + (s << 1) + (c ^ 48);
  }
  return w == 1 ? s : -s;
}
int main() {
  int t = read();
  while (t--) {
    int a = read(), b = read();
    if (a > b) swap(a, b);
    if ((a + b) & 1) {
      int mn = b - (a + b + 1) / 2;
      int mx = min((a + b + 1) / 2, b) + min((a + b) / 2, a);
      printf("%d\n", mx - mn + 1);
      for (int i = mn; i <= mx; i++) {
        printf("%d ", i);
      }
      puts("");
    } else {
      int mn = b - (a + b) / 2;
      int mx = min((a + b) / 2, b) + min((a + b) / 2, a);
      printf("%d\n", (mx / 2 - mn / 2 + 1));
      for (int i = mn; i <= mx; i += 2) {
        printf("%d ", i);
      }
      puts("");
    }
  }
  return 0;
}
