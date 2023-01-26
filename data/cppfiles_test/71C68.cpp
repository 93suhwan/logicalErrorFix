#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return f == 1 ? x : -x;
}
inline void print(int a[], int n, int offset = 0) {
  for (int i = 0; i < n; i++) printf("%d ", a[i + offset]);
  printf("\n");
}
inline void print(long long a[], int n, int offset = 0) {
  for (int i = 0; i < n; i++) printf("%lld ", a[i + offset]);
  printf("\n");
}
const int maxn = 1e6 + 10;
long long n, k, len;
long long base[12], a[20], tmp[20], cnt[10];
bool vis[10], b[10];
inline long long trans(long long a[], long long len) {
  long long res = 0;
  for (int i = len - 1; i >= 0; i--) res = res * 10 + a[i];
  return res;
}
inline void init() {
  n = read();
  k = read();
  memset(a, 0, sizeof(a));
  len = 0;
  long long m = n;
  while (m) a[len++] = m % 10, m /= 10;
}
inline void doit() {
  memset(vis, 0, sizeof(vis));
  int pos = -1, num = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (!vis[a[i]]) {
      if (num >= k) {
        pos = i;
        break;
      }
      vis[a[i]] = true;
      num++;
    }
  }
  if (pos < 0) {
    printf("%lld\n", trans(a, len));
    return;
  }
  for (int i = a[pos] + 1; i <= 9; i++)
    if (vis[i]) {
      a[pos] = i;
      int mnval;
      for (mnval = 0; mnval <= 9; mnval++)
        if (vis[mnval]) break;
      for (int j = 0; j < pos; j++) a[j] = mnval;
      printf("%lld\n", trans(a, len));
      return;
    }
  long long ans = 1e12;
  pos++;
  memcpy(tmp, a, sizeof(a));
  for (int i = pos; i < len; i++) {
    bool flag = false;
    int mnval;
    for (mnval = a[i] + 1; mnval <= 9; mnval++)
      if (vis[mnval]) {
        flag = true;
        break;
      }
    if (!flag) continue;
    a[i] = mnval;
    memset(b, 0, sizeof(b));
    for (int j = i; j < len; j++) b[a[j]] = true;
    int x = 0, v;
    for (int j = 0; j < 10; j++)
      if (b[j]) x++;
    if (x == k) {
      for (v = 0; v < 10; v++)
        if (b[v]) break;
    } else
      v = 0;
    for (int j = 0; j < i; j++) a[j] = v;
    ans = min(ans, trans(a, len));
    break;
  }
  memcpy(a, tmp, sizeof(a));
  for (int i = pos; i < len; i++)
    for (int val = i == pos ? a[i] + 1 : a[i]; val < 10; val++) {
      a[i] = val;
      memset(b, 0, sizeof(b));
      for (int j = i; j < len; j++) b[a[j]] = true;
      int x = 0, v;
      for (int j = 0; j < 10; j++)
        if (b[j]) x++;
      if (x > k) continue;
      if (x == k) {
        for (v = 0; v < 10; v++)
          if (b[v]) break;
      } else
        v = 0;
      for (int j = 0; j < i; j++) a[j] = v;
      long long t = trans(a, len);
      if (t >= n) ans = min(ans, t);
    }
  printf("%lld\n", ans);
}
int main() {
  base[0] = 1;
  for (int i = 1; i < 12; i++) base[i] = base[i - 1] * 10;
  int t = read();
  while (t--) {
    init();
    doit();
  }
  return 0;
}
