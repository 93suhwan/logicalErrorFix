#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s - '0');
    s = getchar();
  }
  x *= f;
}
template <typename T>
void write(T x, char s = '\n') {
  if (!x) {
    putchar('0');
    putchar(s);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  T tmp[25] = {}, t = 0;
  while (x) tmp[t++] = x % 10, x /= 10;
  while (t-- > 0) putchar(tmp[t] + '0');
  putchar(s);
}
const int MAXN = 2e5 + 5;
int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], cnt, n, k;
void add(int u, int v) {
  nxt[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
priority_queue<int, vector<int>, less<int> > q;
int dep[MAXN], f[MAXN], lf;
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  int hs = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    dfs(v, x);
    if (!hs || f[hs] < f[v]) hs = v;
  }
  f[x] = f[hs] + 1;
  if (!hs) lf++;
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa || v == hs) continue;
    q.push(f[v]);
  }
}
int main() {
  read(n), read(k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    add(u, v), add(v, u);
  }
  dfs(1, 0);
  q.push(f[1]);
  int bl = n, r = 0;
  while (!q.empty() && k) {
    bl -= q.top();
    q.pop();
    r++;
    k--;
  }
  if (!bl) {
    if (r < n - r) r += min(k, n / 2 - r);
    write(r * (n - r));
  } else {
    if (bl < r)
      write((r - bl) * (n - r - bl));
    else {
      bl -= r;
      int w = n - r - r;
      write(-min(bl, w / 2) * (w - min(bl, w / 2)));
    }
  }
  return 0;
}
