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
set<pair<int, int> > se;
int t, n, m, a, b, c, vis[100005];
vector<int> v[100005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    se.clear();
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      v[i].clear();
      P[i] = i;
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      if (a > c) swap(a, c);
      v[a].push_back(c);
      if (find_(a) != find_(c)) {
        union_(a, c);
        se.insert({a, c});
      }
    }
    for (auto x : se) {
      printf("%d %d\n", x.first, x.second);
    }
    for (int i = 1; i <= n; i++) {
      if (find_(1) != find_(i)) {
        union_(1, i);
        printf("%d %d\n", 1, i);
      }
    }
  }
}
