#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 5;
int a[M], b[M], c, lst[M], sl[M], ans[M];
struct D {
  int p, s;
};
queue<D> q;
int read() {
  int s = 0, t = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') t = -1;
  for (; isdigit(ch); ch = getchar()) s = s * 10 + ch - '0';
  return s * t;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  int h = n;
  q.push({n, 0});
  while (!q.empty()) {
    int p = q.front().p, s = q.front().s;
    q.pop();
    if (!p) {
      c = s;
      break;
    }
    for (int i = h - 1; i >= p - a[p]; i--)
      lst[i] = p, sl[i + b[i]] = i, q.push({i + b[i], s + 1}), h = i;
  }
  if (!c) return printf("-1"), 0;
  printf("%d\n", c);
  for (int i = 1, x = 0; i <= c; i++, x = sl[lst[x]]) ans[i] = x;
  for (int i = c; i; i--) printf("%d ", ans[i]);
}
