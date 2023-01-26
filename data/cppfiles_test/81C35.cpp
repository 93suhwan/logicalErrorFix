#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 500005;
struct node {
  int l, r, fuck;
  friend bool operator<(const node &x, const node &y) {
    if (x.fuck != y.fuck) return x.fuck < y.fuck;
    return x.l < y.l;
  }
} a[N];
int n, d;
int main() {
  n = read(), d = read();
  for (int i = 1; i <= n; i++) {
    a[i].l = read(), a[i].r = read();
    a[i].fuck = max(a[i].l, a[i].r);
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].l >= d) ans++, ckmax(d, a[i].r);
  }
  printf("%d\n", ans);
  return 0;
}
