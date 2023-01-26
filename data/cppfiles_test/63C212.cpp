#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c & 15), c = getchar();
  return x;
}
const int MAXN = 1000;
int f1[MAXN + 10], f2[MAXN + 10];
int get_fa1(int x) {
  if (f1[x] == x) return x;
  return f1[x] = get_fa1(f1[x]);
}
int get_fa2(int x) {
  if (f2[x] == x) return x;
  return f2[x] = get_fa2(f2[x]);
}
struct node {
  int u, v;
};
int main() {
  int n, m1, m2;
  n = read(), m1 = read(), m2 = read();
  for (int i = 1; i <= n; ++i) f1[i] = f2[i] = i;
  for (int i = 1; i <= m1; ++i) {
    int x = read(), y = read();
    f1[get_fa1(x)] = get_fa1(y);
  }
  for (int i = 1; i <= m2; ++i) {
    int x = read(), y = read();
    f2[get_fa2(x)] = get_fa2(y);
  }
  static node sta[MAXN + 10];
  int top = 0;
  for (int u = 1; u <= n; ++u)
    for (int v = u + 1; v <= n; ++v) {
      if (get_fa1(u) != get_fa1(v) && get_fa2(u) != get_fa2(v)) {
        sta[++top].u = u;
        sta[top].v = v;
        f1[get_fa1(u)] = get_fa1(v);
        f2[get_fa2(u)] = get_fa2(v);
      }
    }
  printf("%d\n", top);
  for (int i = 1; i <= top; ++i) printf("%d %d\n", sta[i].u, sta[i].v);
  return 0;
}
