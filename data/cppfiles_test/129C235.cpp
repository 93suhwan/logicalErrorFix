#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f |= (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
  return f ? -x : x;
}
int a[100007];
bool vis[100007];
inline void work() {
  int n = rd();
  for (int i = 1; i <= n; ++i) {
    a[i] = rd();
    vis[i] = 0;
  }
  sort(a + 1, a + 1 + n);
  int nw = 1, ans = 0;
  for (int i = 1; i <= n; ++i) {
    while (vis[nw] && nw < n) ++nw;
    if (a[i] <= n && !vis[a[i]])
      vis[a[i]] = 1;
    else {
      ++ans;
      int tar = (a[i] - 1) / 2;
      if (tar >= nw)
        vis[nw] = 1;
      else {
        puts("-1");
        return;
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  for (int t = rd(); t; --t) work();
  return 0;
}
