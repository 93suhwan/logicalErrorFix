#include <bits/stdc++.h>
using namespace std;
const int h = 3, ki = 149, mo = 998244353;
int mod(int x) { return (x % mo + mo) % mo; }
int inc(int x, int k) {
  x += k;
  return x < mo ? x : x - mo;
}
int dec(int x, int k) {
  x -= k;
  return x >= 0 ? x : x + mo;
}
int ksm(int x, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1ll * ans * x % mo;
    k >>= 1;
    x = 1ll * x * x % mo;
  }
  return mod(ans);
}
int inv(int x) { return ksm(x, mo - 2); }
int read() {
  char ch = 0;
  int x = 0, flag = 1;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') flag = -1;
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  }
  return x * flag;
}
void write(int x) {
  if (!x) return (void)putchar(48);
  if (x < 0) putchar(45), x = -x;
  int len = 0, p[20];
  while (x) p[++len] = x % 10, x /= 10;
  for (int i = len; i >= 1; i--) putchar(p[i] + 48);
}
void writeln(int x) { write(x), putchar('\n'); }
struct node {
  int x, y;
} p[1100000];
int cnt[520][520];
int c[1100000], lst[1100000], ans[1100000];
int main() {
  int n = read(), m = read(), lim = 500, tot = 0;
  for (int i = 1; i <= n; i++) {
    p[i].x = read(), p[i].y = read();
    p[i].x = min(p[i].x, m);
  }
  for (int o = 1; o <= m; o++) {
    int flag = read(), k = read();
    int x = p[k].x, y = p[k].y;
    if (flag == 1)
      tot++;
    else
      tot--;
    if (x + y > lim) {
      if (flag == 1) {
        for (int i = o; i <= m; i += x + y) c[i]++, c[i + x]--;
        lst[k] = o;
      } else {
        for (int i = lst[k]; i <= m; i += x + y) {
          if (i <= o && o <= i + x - 1) c[o]--, c[i + x]++;
          if (o < i) c[i]--, c[i + x]++;
        }
        lst[k] = 0;
      }
    } else {
      if (flag == 1) {
        for (int i = o; i <= o + x - 1; i++) cnt[x + y][i % (x + y)]++;
        lst[k] = o;
      } else {
        for (int i = lst[k]; i <= lst[k] + x - 1; i++)
          cnt[x + y][i % (x + y)]--;
        lst[k] = 0;
      }
    }
    for (int i = 1; i <= lim; i++) ans[o] += cnt[i][o % i];
    ans[o] -= tot;
  }
  for (int i = 1; i <= m; i++)
    c[i] += c[i - 1], ans[i] += c[i], writeln(-ans[i]);
  return 0;
}
