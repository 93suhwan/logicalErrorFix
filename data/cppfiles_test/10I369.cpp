#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    map<int, int> m;
    int ini[200005] = {0};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &ini[i]);
      if (m[ini[i]] == 0)
        m[ini[i]] = 1;
      else
        m[ini[i]]++;
    }
    long long ans2 = 0;
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
      if (it->second < k) ans2 += it->second;
    }
    int dan[200005] = {0};
    int vis1[200005] = {0};
    for (int i = 0; i < n; i++)
      if (m[ini[i]] >= k && vis1[ini[i]] + 1 <= k) dan[i] = ++vis1[ini[i]];
    for (int i = 1; i <= k; i++) {
      int vis[200005] = {0};
      int cnt = 0;
      for (int j = 0; j < n; j++)
        if (vis[ini[j]] == 0 && dan[j] == 0 && m[ini[j]] < k) {
          vis[ini[j]] = 1;
          dan[j] = i;
          cnt++;
          if (cnt == ans2 / k) break;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", dan[i]);
    printf("\n");
  }
  return 0;
}
