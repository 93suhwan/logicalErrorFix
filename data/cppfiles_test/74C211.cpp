#include <bits/stdc++.h>
using namespace std;
int vis[200010];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int n = a + b;
    memset(vis, 0, sizeof(int) * (n + 5));
    if (a < b) swap(a, b);
    int d = a - b;
    int mn = (d) / 2;
    vis[mn] = vis[n - mn] = 1;
    for (int i = 1; i <= b; i++) {
      mn += 2;
      vis[mn] = vis[n - mn] = 1;
    }
    int cnt = 0;
    for (int i = 0; i <= a + b; i++) {
      if (vis[i]) cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 0; i <= a + b; i++) {
      if (vis[i]) printf("%d ", i);
    }
    printf("\n");
  }
}
