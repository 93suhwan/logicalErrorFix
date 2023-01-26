#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
struct Tree {
  int num, sum;
} st[300005 * 4];
struct Edge {
  int v, to;
} e[300005];
int n, ans, top, size, a[300005], b[300005], f[300005], g[300005], Ans[300005],
    last[300005], head[300005];
bool vis[300005];
queue<int> que;
inline void add(int u, int v) {
  e[++size].v = v;
  e[size].to = head[u];
  head[u] = size;
}
inline Tree up(Tree l, Tree r) {
  Tree ans;
  ans.num = l.num + r.num;
  ans.sum = l.sum + r.sum;
  return ans;
}
inline void build(int node, int l, int r) {
  if (l == r) {
    st[node].num = 0;
    st[node].sum = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
  st[node] = up(st[node << 1], st[node << 1 | 1]);
  return;
}
inline int query(int node, int l, int r, int L, int R) {
  if (st[node].num == st[node].sum) return -1;
  if (L == R) return L;
  int mid = (L + R) >> 1;
  if (r <= mid) return query(node << 1, l, r, L, mid);
  if (l > mid) return query(node << 1 | 1, l, r, mid + 1, R);
  int now = query(node << 1, l, r, L, mid);
  if (now != -1) return now;
  return query(node << 1 | 1, l, r, mid + 1, R);
}
inline void change(int node, int id, int L, int R) {
  if (st[node].num == st[node].sum) return;
  if (L == R) {
    st[node].num = 1;
    return;
  }
  int mid = (L + R) >> 1;
  if (id <= mid) change(node << 1, id, L, mid);
  if (id > mid) change(node << 1 | 1, id, mid + 1, R);
  st[node] = up(st[node << 1], st[node << 1 | 1]);
  return;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    b[i] = min(n, i + read());
    add(b[i], i);
  }
  que.push(n);
  build(1, 1, n);
  vis[n] = 1;
  last[n] = -1;
  g[n] = -1;
  for (int i = head[n]; i; i = e[i].to) {
    int v = e[i].v;
    change(1, v, 1, n);
  }
  ans = -1;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    if (a[now] >= now) {
      ans = now;
      break;
    }
    int num = query(1, now - a[now], now, 1, n);
    while (num != -1) {
      int u = b[num];
      if (!vis[u]) {
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].to) {
          int v = e[i].v;
          change(1, v, 1, n);
        }
        f[u] = f[now] + 1;
        g[u] = num;
        last[u] = now;
        que.push(u);
      }
      num = query(1, now - a[now], now, 1, n);
    }
  }
  if (ans == -1) {
    puts("-1");
  } else {
    writeln(f[ans] + 1);
    Ans[++top] = 0;
    while (g[ans] != -1) {
      Ans[++top] = g[ans];
      ans = last[ans];
    }
    for (int i = top; i >= 1; i--) {
      write(Ans[i]);
      putchar(' ');
    }
  }
  return 0;
}
