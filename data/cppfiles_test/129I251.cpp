#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(b, b + n);
    vector<int> c;
    vector<int> fx(n + 1, 0);
    for (int i = 0; i < n; i++) {
      if (b[i] >= 1 && b[i] <= n && fx[b[i]] == 0) {
        fx[b[i]] = 1;
      } else {
        c.push_back(b[i]);
      }
    }
    int f = 0;
    int cx = 0;
    int p = 0;
    for (int i = 1; i <= n; i++) {
      if (fx[i] == 0) {
        if ((c[p] - (i + 1)) <= (i + 1)) {
          f = 1;
          break;
        } else
          cx += 1;
        p += 1;
      }
    }
    if (f) {
      printf("-1");
    } else {
      printf("%d", cx);
    }
    printf("\n");
  }
  return 0;
}
