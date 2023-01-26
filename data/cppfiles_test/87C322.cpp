#include <bits/stdc++.h>
using namespace std;
map<double, int> mp;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0, count = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      ans = max(ans, x - i);
    }
    printf("%d\n", ans);
  }
  return 0;
}
