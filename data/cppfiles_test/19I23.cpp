#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  x *= f;
}
template <typename _type>
void cmax(_type &a, _type b) {
  if (a < b) a = b;
}
template <typename _type>
void cmin(_type &a, _type b) {
  if (a > b) a = b;
}
const int N = 2e5 + 10, M = 2005;
int i, j, k, m, n, s, t;
int a[N];
int ok[M], tmp[M];
int check(int x) {
  for (i = a[1]; i <= x; i++) ok[i] = 1;
  for (i = 2; i <= n; i++) {
    for (j = 0; j <= x; j++) tmp[j] = ok[j], ok[j] = 0;
    for (j = 0; j <= x; j++) {
      if (tmp[j] && j + a[i] <= x) ok[j + a[i]] = 1;
      if (tmp[j] && j - a[i] >= 0) ok[j - a[i]] = 1;
    }
  }
  int flag = 0;
  for (i = 0; i <= x; i++) flag |= ok[i];
  return flag;
}
signed main() {
  read(t);
  while (t--) {
    read(n);
    for (i = 1; i <= n; i++) read(a[i]);
    int l = a[1], r = 2000, ans = 0;
    while (r >= l) {
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
