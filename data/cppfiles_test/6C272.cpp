#include <bits/stdc++.h>
std::mt19937 rnd(time(0));
using namespace std;
int vis[2000005];
int main() {
  int i, j, n, m, t;
  {
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    int sum = n;
    while (m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      int poi = min(x, y);
      if (vis[poi] == 0) sum--;
      vis[poi]++;
    }
    cin >> t;
    while (t--) {
      int o;
      cin >> o;
      if (o == 3)
        printf("%d\n", sum);
      else if (o == 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        int poi = min(x, y);
        if (vis[poi] == 0) sum--;
        vis[poi]++;
      } else if (o == 2) {
        int x, y;
        scanf("%d%d", &x, &y);
        int poi = min(x, y);
        if (vis[poi] == 1) sum++;
        vis[poi]--;
      }
    }
  }
  return 0;
}
