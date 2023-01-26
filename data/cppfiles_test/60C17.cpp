#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return x * s;
}
map<int, int> M;
int a[200005];
int main() {
  int T = read();
  while (T--) {
    M.clear();
    int n = read();
    long long sum = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), M[a[i]]++, sum += a[i];
    if (sum * 2 % n != 0) {
      printf("0\n");
      continue;
    }
    long long d = sum * 2 / n, ans = 0;
    for (int i = 1; i <= n; i++)
      if (d - a[i] != a[i])
        ans += M[d - a[i]];
      else
        ans += (M[d - a[i]] - 1);
    printf("%lld\n", ans / 2);
  }
  return 0;
}
