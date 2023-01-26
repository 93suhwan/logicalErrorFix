#include <bits/stdc++.h>
using namespace std;
int P[100005];
int find_(int x) {
  if (x == P[x])
    return x;
  else
    return P[x] = find_(P[x]);
}
void union_(int x, int y) { P[find_(x)] = find_(y); }
int t, n, m, a, b, c, vis[100005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) P[i] = i;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      if (a > c) swap(a, c);
      if (find_(a) != find_(c)) {
        union_(a, c);
        printf("%d %d\n", a, c);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (find_(1) != find_(i)) {
        union_(1, i);
        printf("%d %d\n", 1, i);
      }
    }
  }
}
