#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1 << 30;
const long long inff = 1ll << 60;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
struct CatherineUnion {
  int f[N];
  void init(int n) {
    for (int i = 1; i <= n; i++) f[i] = i;
  }
  int find(int x) {
    if (f[x] == x)
      return x;
    else
      return f[x] = find(f[x]);
  }
  void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) f[fy] = fx;
  }
} U1, U2;
int n, m1, m2, u, v;
vector<int> v1, v2, l, r;
int main() {
  int tests = 1;
  while (tests--) {
    n = read(), m1 = read(), m2 = read();
    U1.init(n), U2.init(n);
    for (int i = 1; i <= m1; i++) u = read(), v = read(), U1.merge(u, v);
    for (int i = 1; i <= m2; i++) u = read(), v = read(), U2.merge(u, v);
    for (int i = 2; i <= n; i++) {
      int fa1 = U1.find(1), fa2 = U2.find(1);
      int fafa1 = U1.find(i), fafa2 = U2.find(i);
      if (fafa1 != fa1 && fafa2 != fa2) {
        U1.merge(1, i), U2.merge(1, i);
        l.push_back(1), r.push_back(i);
      }
    }
    for (int i = 2; i <= n; i++) {
      int fa1 = U1.find(1), fa2 = U2.find(1);
      int fafa1 = U1.find(i), fafa2 = U2.find(i);
      if (fafa1 != fa1) {
        U1.merge(1, i);
        v1.push_back(i);
      } else if (fafa2 != fa2) {
        U2.merge(1, i);
        v2.push_back(i);
      }
    }
    int sz1 = l.size(), sz2 = min(v1.size(), v2.size());
    printf("%d\n", sz1 + sz2);
    for (int i = 0; i < sz1; i++) printf("%d %d\n", l[i], r[i]);
    for (int i = 0; i < sz2; i++) printf("%d %d\n", v1[i], v2[i]);
  }
  return 0;
}
