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
      vis[a] = 1;
      vis[c] = 1;
      if (a > c) swap(a, c);
      v[a].push_back(c);
      se.insert({a, c});
    }
    for (auto x : se) {
      printf("%d %d\n", x.first, x.second);
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 1) {
        for (auto x : v[i]) {
          union_(x, i);
        }
      } else {
        printf("%d %d\n", 1, i);
        union_(1, i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (find_(i) != find_(1)) {
        union_(1, i);
        printf("%d %d\n", 1, i);
      }
    }
  }
}
