#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, x, y, tot = 2, head[1101], dep[1101], ans2, fy;
bool book[1101];
long long w, ans, aa[1101];
long long mn(long long x, long long y) { return (x > y ? y : x); }
struct f {
  int to, net;
  long long w, fy;
} a[100011];
int b[100011];
void add(int x, int y, long long w, long long fy) {
  a[tot].to = y, a[tot].w = w, a[tot].net = head[x], a[tot].fy = fy,
  head[x] = tot++;
  return;
}
bool spfa() {
  memset(dep, 0xcf, sizeof(dep));
  memset(book, 0, sizeof(book));
  queue<int> u;
  u.push(s);
  book[s] = 1, dep[s] = 0;
  while (u.size()) {
    y = u.front();
    u.pop();
    book[y] = 0;
    for (int j = head[y]; j; j = a[j].net) {
      if (a[j].w != 0 && dep[y] + a[j].fy > dep[a[j].to]) {
        dep[a[j].to] = dep[y] + a[j].fy;
        if (!book[a[j].to]) book[a[j].to] = 1, u.push(a[j].to);
      }
    }
  }
  return dep[t] > 0;
}
int dfs(int x, long long in) {
  int out = 0;
  book[x] = 1;
  if (x == t) return in;
  for (int i = head[x]; i; i = a[i].net) {
    if ((!book[a[i].to] || a[i].to == t) && dep[a[i].to] == dep[x] + a[i].fy &&
        a[i].w) {
      int addd = dfs(a[i].to, min(in - out, a[i].w));
      if (addd > 0) {
        out += addd;
        a[i].w -= addd;
        a[i ^ 1].w += addd;
        if (out == in) break;
      }
    }
  }
  return out;
}
int main() {
  scanf("%d%d", &n, &m);
  s = n + 1, t = s + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &aa[i]);
    add(s, i, 1, 0);
    add(i, s, 0, 0);
    add(i, t, 1, 0);
    add(t, i, 0, 0);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    add(x, y, 2e15, aa[x] - aa[y]);
    add(y, x, 0, aa[y] - aa[x]);
  }
  while (spfa()) {
    do {
      memset(book, 0, sizeof(book));
      dfs(s, 1e18);
    } while (book[t]);
  }
  memset(dep, -0x3f, sizeof(dep));
  queue<int> u;
  u.push(s);
  book[s] = 1, dep[s] = 0;
  while (u.size()) {
    y = u.front();
    u.pop();
    book[y] = 0;
    for (int j = head[y]; j; j = a[j].net) {
      if (a[j].w != 0 && dep[y] + a[j].fy > dep[a[j].to]) {
        dep[a[j].to] = dep[y] + a[j].fy;
        b[a[j].to] = j;
        if (!book[a[j].to]) book[a[j].to] = 1, u.push(a[j].to);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%lld ", aa[i] + dep[i]);
  return 0;
}
