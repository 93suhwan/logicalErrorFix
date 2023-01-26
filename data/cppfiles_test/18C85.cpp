#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int a[N], v[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      v[i] = INF;
      if (a[i] == 0) v[i] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 0) {
        int L = i;
        while (v[L] < v[(L + d) % n]) {
          v[(L + d) % n] = v[L] + 1;
          L = (L + d) % n;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(v[i], res);
    if (res == INF)
      printf("-1\n");
    else
      printf("%d\n", res);
  }
  return 0;
}
