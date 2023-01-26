#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    map<int, int> m;
    int ini[2005] = {0};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &ini[i]);
      if (m[ini[i]] == 0)
        m[ini[i]] = 1;
      else
        m[ini[i]]++;
    }
    int ans = 0;
    int ans2 = 0;
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
      if (it->second > k)
        ans++;
      else
        ans2 += it->second;
    }
    ans += ans2 / k;
    int dan[2005] = {0};
    for (int i = 1; i <= k; i++) {
      int vis[2005] = {0};
      int cnt = 0;
      for (int j = 0; j < 2005; j++)
        if (!vis[ini[j]] && !dan[j]) {
          vis[ini[j]] = 1;
          dan[j] = i;
          cnt++;
          if (cnt == ans) break;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", dan[i]);
    printf("\n");
  }
  return 0;
}
