#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 2;
unsigned int w[N];
int c[N][2], v[N], s[N], f[N], p[N];
int kth;
bool ed[N];
inline void pushup(const int x) { s[x] = s[c[x][0]] + s[c[x][1]] + 1; }
void split(int now, int &x, int &y) {
  if (!now) return x = y = 0, void();
  if (kth <= s[c[now][0]])
    f[c[now][0]] = 0, split(c[y = now][0], x, c[now][0]), f[c[now][0]] = now;
  else
    kth -= s[c[now][0]] + 1, f[c[now][1]] = 0,
                             split(c[x = now][1], c[now][1], y),
                             f[c[now][1]] = now;
  pushup(now);
}
int merge(int x, int y) {
  if (!(x && y)) return x | y;
  if (w[x] < w[y]) {
    c[x][1] = merge(c[x][1], y);
    f[c[x][1]] = x;
    pushup(x);
    return x;
  } else {
    c[y][0] = merge(x, c[y][0]);
    f[c[y][0]] = y;
    pushup(y);
    return y;
  }
}
int getkth(int x) {
  int r = s[c[x][0]] + 1;
  while (f[x]) {
    if (c[f[x]][1] == x) r += s[c[f[x]][0]] + 1;
    x = f[x];
  }
  return r;
}
int findroot(int x) {
  while (f[x]) x = f[x];
  return x;
}
int make_lst_root(int x) {
  kth = getkth(x);
  int rt = findroot(x);
  if (!kth) return rt;
  int p;
  split(rt, p, rt);
  return merge(rt, p);
}
int main() {
  int n, q, i, j;
  cin >> n >> q;
  for (i = 1; i <= n; i++) w[i] = rnd();
  for (i = 1; i <= n; i++) cin >> p[i], s[i] = 1;
  for (i = 1; i <= n; i++)
    if (!ed[i] && p[i] != i) {
      int rt = i;
      for (ed[i] = 1, j = p[i]; !ed[j]; j = p[j]) ed[j] = 1, rt = merge(rt, j);
    }
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      if (x == y) continue;
      int rt1 = make_lst_root(x);
      int rt2 = findroot(y);
      if (rt1 == rt2) {
        kth = getkth(y);
        int p;
        split(rt1, rt1, p);
      } else {
        make_lst_root(y);
        merge(rt1, rt2);
      }
    } else {
      int rt = make_lst_root(x);
      y %= s[rt];
      if (y == 0) {
        cout << x << '\n';
        continue;
      }
      int q;
      kth = y;
      split(rt, rt, q);
      int p = rt;
      while (c[p][1]) p = c[p][1];
      cout << p << '\n';
      merge(rt, q);
    }
  }
}
