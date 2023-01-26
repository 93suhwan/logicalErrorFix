#include <bits/stdc++.h>
using namespace std;
int judge[100005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      judge[b] = 1;
    }
    int loc = -1;
    for (int i = 1; i <= n; i++) {
      if (!judge[i]) {
        loc = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != loc) printf("%d %d\n", i, loc);
    }
  }
}
