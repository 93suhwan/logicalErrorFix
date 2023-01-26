#include <bits/stdc++.h>
using namespace std;
int lst[20][200002] = {0};
int main() {
  for (int i = 1; i < 200002; i++) {
    for (int j = 0; j < 20; j++) {
      if (i & (1 << j)) {
        lst[j][i] = 1;
      }
      lst[j][i] += lst[j][i - 1];
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int maxm = 0;
    for (int i = 0; i < 20; i++) {
      maxm = max(maxm, lst[i][r] - lst[i][l - 1]);
    }
    printf("%d\n", r - l + 1 - maxm);
  }
  return 0;
}
