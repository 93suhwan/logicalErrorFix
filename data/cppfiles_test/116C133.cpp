#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> dp1(n + 2), dp2(n + 2);
    dp1[0] = 1;
    while (n--) {
      int x;
      scanf("%d", &x);
      dp1[x + 1] = add(dp1[x + 1], dp1[x + 1]);
      dp1[x + 1] = add(dp1[x + 1], dp1[x]);
      if (x > 0) dp2[x - 1] = add(dp2[x - 1], dp2[x - 1]);
      if (x > 0) dp2[x - 1] = add(dp2[x - 1], dp1[x - 1]);
      dp2[x + 1] = add(dp2[x + 1], dp2[x + 1]);
    }
    int ans = 0;
    for (int x : dp1) ans = add(ans, x);
    for (int x : dp2) ans = add(ans, x);
    printf("%d\n", add(ans, MOD - 1));
  }
}
