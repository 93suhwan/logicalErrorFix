#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
const int maxn = 1e9;
const int mod = 998244353;
int main() {
  int t = read();
  while (t--) {
    int a = read(), b = read();
    int y = abs(a - b) / 2;
    if (((a + b) & 1) == 0)
      printf("%d\n", (a + b) / 2 - y + 1);
    else
      printf("%d\n", a + b - 2 * y + 1);
    for (int i = 0; i + y <= a + b - y; ++i) {
      if (((a + b) & 1) == 0) {
        if ((i & 1) == 0) cout << i + y << ' ';
      } else
        printf("%d ", i + y);
    }
    cout << endl;
  }
  return 0;
}
