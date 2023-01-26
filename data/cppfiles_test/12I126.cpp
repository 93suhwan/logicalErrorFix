#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    if (k > n * (m / 2))
      puts("NO");
    else if (k % 2 == 0)
      puts("YES");
    else
      puts("NO");
  } else {
    int x = m / 2;
    int y = k / x;
    if (y % 2 == 0 || k % x != 0 || k == 0)
      puts("NO");
    else
      puts("YES");
  }
}
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
