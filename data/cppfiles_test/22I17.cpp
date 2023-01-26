#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int stack[20];
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int top = 0;
  while (x) stack[++top] = x % 10, x /= 10;
  while (top) putchar(stack[top--] + '0');
}
inline void pr1(int x) {
  write(x);
  putchar(' ');
}
inline void pr2(int x) {
  write(x);
  puts("");
}
int t[200010];
int a[200010], b[200010], pt[200010], tp[450][200010];
int main() {
  int n = read(), m = read(), pd = sqrt(m);
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
  for (int i = 1; i <= m; i++) {
    int op = read(), k = read();
    if (op == 1)
      t[k] = i;
    else {
      int l = t[k], r = i - 1, ul = a[k] + b[k];
      if (ul <= pd) {
        for (int j = l + a[k]; j <= l + ul - 1; j++) {
          tp[ul][j]++;
          int uf = ceil(1.0 * (r - j) / ul);
          if ((r - j) % ul == 0) uf++;
          int fu = j + uf * ul;
          if (fu <= m) tp[ul][fu]--;
        }
      } else {
        for (int j = l; j <= r; j += ul) {
          if (j + a[k] > r) break;
          pt[j + a[k]]++;
          pt[min(r + 1, j + ul)]--;
        }
      }
      t[k] = 0;
    }
  }
  for (int k = 1; k <= n; k++) {
    if (t[k]) {
      int l = t[k], r = m, ul = a[k] + b[k];
      if (ul <= pd) {
        for (int j = l + a[k]; j <= l + ul - 1; j++) {
          tp[ul][j]++;
          int uf = ceil(1.0 * (r - j) / ul);
          if ((r - j) % ul == 0) uf++;
          int fu = j + uf * ul;
          if (fu <= m) tp[ul][fu]--;
        }
      } else {
        for (int j = l; j <= r; j += ul) {
          if (j + a[k] > r) break;
          pt[j + a[k]]++;
          pt[min(r + 1, j + ul)]--;
        }
      }
      t[k] = 0;
    }
  }
  for (int i = 1; i <= m; i++) pt[i] += pt[i - 1];
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= pd; j++) {
      if (i > j) tp[j][i] += tp[j][i - j];
      pt[i] += tp[j][i];
    }
    pr2(pt[i]);
  }
  return 0;
}
