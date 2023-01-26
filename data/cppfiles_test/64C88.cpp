#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
struct bing {
  int fa[N];
  void init() {
    for (int i = (1); i < (N); i++) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void unite(int x, int y) { fa[find(x)] = find(y); }
  bool same(int x, int y) { return find(x) == find(y); }
} bi[2];
int n, m1, m2;
int main() {
  for (int i = (0); i < (2); i++) bi[i].init();
  cin >> n >> m1 >> m2;
  int op = m1 > m2 ? 0 : 1;
  for (int i = (1); i < (m1 + 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    bi[op].unite(u, v);
  }
  for (int i = (1); i < (m2 + 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    bi[1 - op].unite(u, v);
  }
  printf("%d\n", min(n - 1 - m1, n - 1 - m2));
  for (int i = (1); i < (n + 1); i++)
    if (!bi[0].same(1, i) && !bi[1].same(1, i)) {
      bi[0].unite(1, i), bi[1].unite(1, i);
      printf("%d %d\n", 1, i);
    }
  for (int a = 2, b = 2; a <= n; a++) {
    if (bi[0].same(1, a)) continue;
    while (b <= n && bi[1].same(1, b)) b++;
    if (b <= n) {
      bi[0].unite(a, b), bi[1].unite(a, b);
      printf("%d %d\n", a, b);
    }
  }
  return 0;
}
