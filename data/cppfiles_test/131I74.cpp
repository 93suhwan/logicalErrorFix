#include <bits/stdc++.h>
using namespace std;
const int N = 200005 * 32, mod = 1000000007;
int ans = 0, ans1 = 0, ans2 = 0, tol = 0, d1[N] = {0}, d2[N] = {0}, s1[N] = {0},
    s2[N] = {0}, lx[N] = {0};
map<int, int> my;
vector<int> e[N];
int get(int x) {
  int i = 0;
  for (i = 0;; i++) {
    if ((1 << i) >= x) return (1 << i) - x;
  }
}
void f(int x) {
  int i = 0, y = 0, now = 0;
  s1[x] = x;
  sort(e[x].begin(), e[x].end());
  for (i = 0; i < e[x].size(); i++) {
    if (i && e[x][i] == e[x][i - 1]) continue;
    y = e[x][i];
    f(y);
    now = d1[y] + 1;
    if (now > d1[x]) {
      d2[x] = d1[x];
      s2[x] = s1[x];
      d1[x] = now;
      s1[x] = s1[y];
    } else if (now > d2[x]) {
      d2[x] = now;
      s2[x] = s1[y];
    }
  }
  if (d1[x] + d2[x] > ans) {
    ans = d1[x] + d2[x];
    ans1 = s1[x];
    ans2 = s2[x];
  }
}
void solve() {
  int n = 0, x = 0, y = 0, tx = 0, ty = 0, i = 0;
  scanf("%d", &n);
  my[0] = ++tol;
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    tx = my[x];
    if (!tx) {
      my[x] = tx = ++tol;
    }
    lx[tx] = i;
    while (x) {
      y = get(x);
      ty = my[y];
      if (!ty) {
        my[y] = ty = ++tol;
      }
      e[ty].push_back(tx);
      x = y;
      tx = ty;
    }
  }
  ans = 0;
  f(1);
  printf("%d %d %d\n", lx[ans1], lx[ans2], ans);
}
int main() {
  int o = 1;
  while (o--) {
    solve();
  }
  return 0;
}
