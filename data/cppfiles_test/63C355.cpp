#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * flag;
}
long long mod = 1e9 + 7;
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y % 2) ans = ans * x % mod;
    x = x * x % mod;
    y = y / 2;
  }
  return ans;
}
long long fa[1005];
long long faa[1005];
long long f(long long x) {
  while (fa[x] != x) {
    x = fa[x] = fa[fa[x]];
  }
  return x;
}
long long ff(long long x) {
  while (faa[x] != x) {
    x = faa[x] = faa[faa[x]];
  }
  return x;
}
int main() {
  long long n = read(), m1 = read(), m2 = read();
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    faa[i] = i;
  }
  for (int i = 1; i <= m1; i++) {
    long long x = read(), y = read();
    long long xx = f(x);
    long long yy = f(y);
    fa[xx] = yy;
  }
  for (int i = 1; i <= m2; i++) {
    long long x = read(), y = read();
    long long xx = ff(x);
    long long yy = ff(y);
    faa[xx] = yy;
  }
  vector<pair<int, int>> ans;
  int num = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (i == j) continue;
      long long xx = f(i);
      long long yy = f(j);
      if (xx == yy) continue;
      xx = ff(i);
      yy = ff(j);
      if (xx == yy) continue;
      ans.push_back(make_pair(j, i));
      faa[xx] = yy;
      xx = f(i);
      yy = f(j);
      fa[xx] = yy;
      num++;
    }
  }
  printf("%d\n", num);
  for (int i = 0; i < num; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
