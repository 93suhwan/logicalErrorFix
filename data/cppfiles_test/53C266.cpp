#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long tt, k, n, sum = 0, a[200005], b[200005];
int main() {
  tt = read();
  while (tt--) {
    n = read();
    k = read();
    for (int(i) = 1; i <= (n); ++i) {
      a[i] = read();
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    long long tot = unique(b + 1, b + 1 + n) - b - 1;
    for (int(i) = 1; i <= (n); ++i)
      a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
    sum = 1;
    for (int i = 2; i <= n; i++)
      if (a[i] != a[i - 1] + 1) sum++;
    if (sum <= k)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
