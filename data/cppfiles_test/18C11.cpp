#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, k, x, y;
bool st[N];
vector<int> g;
struct node {
  int x, y;
  bool operator<(const node& t) const { return x < t.x; }
} e[N];
bool check(node a, node b) {
  if (b.x > a.x && b.x < a.y && b.y > a.y) return 1;
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    g.clear();
    memset(st, 0, sizeof st);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &x, &y);
      if (x > y) swap(x, y);
      e[i] = {x, y}, st[x] = st[y] = 1;
    }
    for (int i = 1; i <= 2 * n; i++)
      if (st[i] == 0) g.push_back(i);
    for (int i = 0; i < g.size() / 2; i++)
      e[k + i] = {g[i], g[i + g.size() / 2]};
    sort(e, e + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (check(e[i], e[j])) ans++;
      }
    printf("%d\n", ans);
  }
  return 0;
}
