#include <bits/stdc++.h>
using namespace std;
int t, n, m;
bool visited[1000005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      int t1, t2, t3;
      scanf("%d%d%d", &t1, &t2, &t3);
      visited[t2] = true;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        root = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      visited[i] = false;
      if (i == root) continue;
      printf("%d %d\n", root, i);
    }
  }
  return 0;
}
