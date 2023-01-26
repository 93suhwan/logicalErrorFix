#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
const int N = 200005;
struct node {
  int a, b;
} p[N];
int n, c[N], t[N];
bool cmp(node A, node B) { return A.a < B.a; }
void update(int x, int v) {
  while (x <= n) {
    t[x] = max(t[x], v);
    x += x & (-x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res = max(res, t[x]);
    x -= x & (-x);
  }
  return res;
}
int main() {
  n = io::read<int>();
  for (int i = 1; i <= n; ++i) {
    p[i].b = io::read<int>();
    p[i].a = i - p[i].b;
  }
  sort(p + 1, p + n + 1, cmp);
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (p[i].a >= 0) c[++tot] = p[i].b;
  }
  int ans = 0;
  for (int i = 1; i <= tot; ++i) {
    int res = query(c[i] + 1);
    ans = max(ans, res + 1);
    update(c[i] + 1, res + 1);
  }
  printf("%d\n", ans);
  return 0;
}
