#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
int read() {
  int p = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) p = (p << 1) + (p << 3) + (c ^ 48), c = getchar();
  return p * f;
}
int main() {
  int t = read();
  while (t--) {
    int cnt = 0;
    int n = read(), k = read();
    int pre = inf;
    for (int i = 1; i <= n; i++) {
      int tmp = read();
      if (tmp < pre) cnt++;
      pre = tmp;
    }
    if (cnt > k)
      puts("No");
    else
      puts("Yes");
  }
  return 0;
}
