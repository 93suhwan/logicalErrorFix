#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T>
void read(T &x) {
  x = 0;
  int c = getchar();
  int flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
template <class T>
T _max(T a, T b) {
  return b < a ? a : b;
}
template <class T>
T _min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
bool checkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 1000005;
int n;
int a[N], b[N], sa[N], sb[N];
void init() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) read(b[i]);
  sa[n + 1] = 0;
  for (int i = n; i >= 1; --i) sa[i] = sa[i + 1] + a[i];
  sb[0] = 0;
  for (int i = 1; i <= n; ++i) sb[i] = sb[i - 1] + b[i];
}
void solve() {
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    int w = max(sb[i - 1], sa[i + 1]);
    if (i == 1)
      ans = w;
    else
      checkmin(ans, w);
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  read(t);
  while (t--) {
    init();
    solve();
  }
  return 0;
}
