#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline long long rd() {
  char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c);
       c = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    f ^= !(c ^ 45);
  for (; isdigit(c);
       c = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int i, j, k, n, m, t, it, a[1005000], fa[10005000];
bool op[10050000];
struct SB {
  int id, x, y;
  bool operator<(const SB a) const { return (x == a.x) ? y < a.y : x < a.x; }
};
vector<SB> v1, v2;
int main() {
  ios::sync_with_stdio(0);
  t = rd();
  while (t--) {
    n = rd();
    it = 0;
    for (i = 1; i <= n; i++) a[i] = rd();
    v1.push_back({0, -11451419, -11451419});
    for (i = 1; i <= n; i++) {
      v2.clear();
      for (auto &[id, x, y] : v1) {
        if (x < -a[i]) {
          fa[++it] = id;
          op[it] = 1;
          v2.push_back({it, -a[i], y});
          goto aaa;
        }
        if (y < -a[i]) {
          fa[++it] = id;
          op[it] = 1;
          v2.push_back({it, x, -a[i]});
          goto aaa;
        }
      aaa:;
        if (x < a[i]) {
          fa[++it] = id;
          op[it] = 0;
          v2.push_back({it, a[i], y});
          goto bbb;
        }
        if (y < a[i]) {
          fa[++it] = id;
          op[it] = 0;
          v2.push_back({it, x, a[i]});
          goto bbb;
        }
      bbb:;
      }
      if (v2.empty()) {
        puts("NO");
        goto ccc;
      }
      v1.clear();
      k = 1e9;
      sort(v2.begin(), v2.end());
      for (auto &i : v2) {
        if (i.y < k) {
          k = i.y;
          v1.push_back(i);
        }
      }
    }
    i = (*v1.begin()).id;
    j = n;
    while (i) {
      if (op[i]) a[j] *= -1;
      j--;
      i = fa[i];
    }
    puts("YES");
    for (i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
  ccc:;
  }
}
