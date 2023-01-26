#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    const int Z = 1e5 + 10;
    int n, a[Z], mn = 1, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (i > 0)
        if (a[i] < a[i - 1]) ++mn;
    }
    mn <= k ? puts("Yes") : puts("No");
  }
  return 0;
}
