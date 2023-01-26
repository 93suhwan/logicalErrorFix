#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int n, a[N], b[N], c[N], d[N], wc, wd, vi[N], sum;
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
int get(int op) {
  int pos = rand() % n + 1;
  while (vi[pos] == 1 - op) pos = rand() % n + 1;
  return pos;
}
signed main() {
  srand(time(0));
  n = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  sort(b + 1, b + 1 + n);
  int w = unique(b + 1, b + 1 + n) - b - 1;
  if (w != n) {
    printf("Yes\n");
    for (int i = 1; i <= w; i++) printf("%d ", b[i]);
    for (int i = 1; i <= n - w; i++) printf("0 ");
    printf("\n");
    return 0;
  }
  bool bl = 1;
  for (int i = 1; i <= n; i++)
    if (b[i] % 2 == 0) bl = 0;
  if (!bl) {
    int t[2];
    t[0] = t[1] = 0;
    for (int i = 1; i <= n; i++) t[b[i] & 1]++;
    int A = -1, B = -1, C = -1;
    for (int i = 1; i <= n && A == -1; i++)
      for (int j = 1; j < i && A == -1; j++) {
        t[b[i] & 1]--;
        t[b[j] & 1]--;
        int now = (b[i] + b[j]) % 2;
        if (t[now]) {
          A = i;
          B = j;
          for (int k = 1; k <= n; k++)
            if (k != i && k != j && now == b[k] % 2) C = k;
          break;
        }
        t[b[i] & 1]++;
        t[b[j] & 1]++;
      }
    if (A == -1) {
      printf("No\n");
      return 0;
    }
    a[1] = b[A] + b[B] - b[C];
    a[1] /= 2;
    for (int i = 1, j = 2; i <= n; i++)
      if (i != C) a[j++] = b[i] - a[1];
    printf("Yes\n");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
  }
  if (n & 1) printf("No\n");
  int m = n / 2, all = 0;
  for (int i = 1; i <= n; i++) all += b[i];
  all /= 2;
  for (int i = 1; i <= m - m / 2; i++) vi[i] = 1, sum += b[i];
  for (int i = n - m / 2 + 1; i <= n; i++) vi[i] = 1, sum += b[i];
  for (int ti = 1; ti <= 5000000; ti++) {
    if (all == sum) break;
    int x = get(0), y = get(1);
    if (abs(sum + b[x] - b[y] - all) <= abs(sum - all)) {
      vi[x] = 1;
      vi[y] = 0;
      sum += b[x] - b[y];
    }
  }
  if (sum != all) {
    printf("No\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (vi[i])
      c[++wc] = b[i];
    else
      d[++wd] = b[i];
  }
  int wh = 2;
  while (wc || wd) {
    a[wh] = c[wc--] - a[wh - 1];
    wh++;
    a[wh] = d[wd--] - a[wh - 1];
    wh++;
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
}
