#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int r = 0; r < t; r++) {
    int n, ans = 0xffffffff;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int t;
      scanf("%d", &t);
      ans &= t;
    }
    printf("%d\n", ans);
  }
}
