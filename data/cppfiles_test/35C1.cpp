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
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
struct Tree {
  int minn;
} st[1000005 * 4];
int n, m, size, a[1000005], f[1000005], vis[1000005], pri[1000005],
    last[1000005];
long long ans, g[1000005];
char s[1000005];
stack<int> e[100000];
inline void change(int node, int l, int r, int id, int k) {
  if (l == r) {
    st[node].minn = k;
    return;
  }
  int mid = (l + r) >> 1;
  if (id <= mid) {
    change(node << 1, l, mid, id, k);
  } else {
    change(node << 1 | 1, mid + 1, r, id, k);
  }
  st[node].minn = min(st[node << 1].minn, st[node << 1 | 1].minn);
  return;
}
inline int query(int node, int l, int r, int L, int R) {
  if (L >= l && R <= r) return st[node].minn;
  int mid = (L + R) >> 1;
  if (r <= mid) return query(node << 1, l, r, L, mid);
  if (l > mid) return query(node << 1 | 1, l, r, mid + 1, R);
  return min(query(node << 1, l, r, L, mid),
             query(node << 1 | 1, l, r, mid + 1, R));
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    f[i] = i;
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    if (a[i] == 1) s[i] = '*';
  for (int i = 2; i <= 1000000; i++) {
    if (!vis[i]) {
      pri[++size] = i;
      vis[i] = size;
      last[i] = i;
    }
    for (int j = 1; j <= size && i * pri[j] <= 1000000; j++) {
      int k = i * pri[j];
      vis[k] = 1;
      last[k] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] = i;
    if (s[i] == '*') {
      while (a[i] != 1) {
        e[vis[last[a[i]]]].push(i);
        a[i] = a[i] / last[a[i]];
      }
    } else {
      while (a[i] != 1) {
        if (e[vis[last[a[i]]]].empty()) {
          f[i] = 0;
        } else {
          f[i] = min(f[i], e[vis[last[a[i]]]].top());
          e[vis[last[a[i]]]].pop();
        }
        a[i] = a[i] / last[a[i]];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] && f[i] <= i - 1) f[i] = query(1, f[i], i - 1, 1, n);
    change(1, 1, n, i, f[i]);
  }
  g[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '*') {
      g[i] = g[i - 1] + 1;
    } else {
      if (!f[i]) continue;
      g[i] = g[f[i] - 1] + 1;
    }
    ans += g[i];
  }
  writeln(ans);
  return 0;
}
