#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 10;
int n;
int a[NR];
int cal(int x) {
  if (x == 0) return -1;
  int l = 0, r = 30, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if ((1 << mid) >= x)
      res = (1 << mid) - x, r = mid - 1;
    else
      l = mid + 1;
  }
  return res;
}
map<int, int> book;
int cnt, vis[NR * 32], b[NR * 32];
struct arr {
  int to, nxt;
} g[NR * 32];
int fte[NR * 32], gsz;
void addedge(int x, int y) {
  g[++gsz] = (arr){y, fte[x]};
  fte[x] = gsz;
}
int ans, ans1, ans2;
int f[NR * 32][2], s[NR * 32];
void dfs(int x, int fa) {
  int max1 = 0, mx1 = 0, max2 = 0, mx2 = 0;
  if (s[x]) mx1 = x;
  for (int i = fte[x]; i; i = g[i].nxt) {
    int y = g[i].to;
    if (y == fa) continue;
    dfs(y, x);
    if (f[y][0] + 1 >= max1)
      max2 = max1, mx2 = mx1, max1 = f[y][0] + 1, mx1 = f[y][1];
    else if (f[y][0] + 1 >= max2)
      max2 = f[y][0] + 1, mx2 = f[y][1];
  }
  f[x][0] = max1, f[x][1] = mx1;
  if (mx1 && mx2) {
    if (max1 + max2 > ans) ans = max1 + max2, ans1 = mx1, ans2 = mx2;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int tmp = a[i], last = -1;
    while (tmp != -1) {
      int nxt = cal(tmp);
      if (book[tmp] == 0) book[tmp] = ++cnt, b[cnt] = tmp;
      int x = book[tmp];
      if (last != -1) addedge(x, last);
      if (vis[x]) break;
      vis[x] = 1;
      tmp = nxt;
      last = x;
    }
    s[book[a[i]]] = i;
  }
  dfs(book[0], 0);
  printf("%d %d %d\n", s[ans1], s[ans2], ans);
  return 0;
}
