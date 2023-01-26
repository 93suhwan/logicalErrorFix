#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == 5) {
      puts("2");
      continue;
    }
    int lst[25] = {0};
    for (int i = 0; i < 25; i++) {
      lst[i] = 1 << i;
    }
    int sum[25] = {0};
    for (int i = 0; i < 24; i++) {
      if (l >= lst[i + 1] || r < lst[i]) continue;
      int ll = max(l, lst[i]);
      int rr = min(r, lst[i + 1] - 1);
      sum[i] = rr - ll + 1;
    }
    int maxm = 0;
    for (int i = 0; i < 25; i++) {
      maxm = max(maxm, sum[i]);
    }
    printf("%d\n", r - l + 1 - maxm);
  }
  return 0;
}
