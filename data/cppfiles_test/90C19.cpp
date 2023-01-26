#include <bits/stdc++.h>
using namespace std;
int a[100010];
void solve() {
  long long x, y;
  scanf("%lld%lld", &x, &y);
  if (x == y)
    printf("%lld\n", x);
  else {
    if (x > y)
      printf("%lld\n", x + y);
    else {
      printf("%lld\n", ((y / x) * x + y) / 2);
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
