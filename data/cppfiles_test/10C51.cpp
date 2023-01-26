#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int add(int x, int y) {
  int ret = x + y;
  if (ret >= mod) ret -= mod;
  return ret;
}
inline int sub(int x, int y) {
  int ret = x - y;
  if (ret < 0) ret += mod;
  return ret;
}
inline int mul(int x, int y) { return ((long long)x * y) % mod; }
inline int step(int base, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, base);
    base = mul(base, base);
    pw >>= 1;
  }
  return ret;
}
inline int invv(int x) { return step(x, mod - 2); }
const int maxn = 1e5 + 10;
int m, n, k, r, c, ax, ay, bx, by;
struct rect {
  int x1, x2, y1, y2;
  long long surface() {
    if (x1 > x2 || y1 > y2) return 0;
    return ((long long)x2 - x1 + 1) * (y2 - y1 + 1);
  }
};
rect intersect(rect &a, rect &b) {
  rect ret;
  ret.x1 = max(a.x1, b.x1);
  ret.x2 = min(a.x2, b.x2);
  ret.y1 = max(a.y1, b.y1);
  ret.y2 = min(a.y2, b.y2);
  return ret;
}
int go(rect a, rect b) {
  if (intersect(a, b).surface() == 0ll) return step(k, a.surface() % (mod - 1));
  if (a.surface() == intersect(a, b).surface())
    return step(k, a.surface() % (mod - 1));
  rect pom = intersect(a, b);
  rect pom2 = pom;
  int dx = a.x1 - b.x1;
  int dy = a.y1 - b.y1;
  pom2.x1 += dx;
  pom2.y1 += dy;
  pom2.x2 += dx;
  pom2.y2 += dy;
  int ret = step(k, (a.surface() - pom.surface() - pom2.surface() +
                     intersect(pom, pom2).surface()) %
                        (mod - 1));
  ret = mul(ret, go(pom, pom2));
  return ret;
}
int main() {
  scanf("%d %d %d %d %d", &n, &m, &k, &r, &c);
  scanf("%d %d %d %d", &ax, &ay, &bx, &by);
  rect a = {ax, ax + r - 1, ay, ay + c - 1};
  rect b = {bx, bx + r - 1, by, by + c - 1};
  int rez = step(k, ((long long)n * m -
                     (a.surface() + b.surface() - intersect(a, b).surface())) %
                        (mod - 1));
  rez = mul(rez, go(a, b));
  printf("%d\n", rez);
  return 0;
}
