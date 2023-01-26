#include <bits/stdc++.h>
using namespace std;
void init() {}
long long doit(int n, int md) {
  long long pow2 = 1ll << md;
  int num1[21], num2[21];
  int p1 = 0, p2 = 0;
  while (n) {
    num1[p1++] = n % 10;
    n /= 10;
  }
  while (pow2) {
    num2[p2++] = pow2 % 10;
    pow2 /= 10;
  }
  reverse(num1, num1 + p1);
  reverse(num2, num2 + p2);
  long long ans = 0;
  for (int i = 0, q = 0; i < p1 && q < p2; i++) {
    if (num1[i] == num2[q]) {
      ans++;
      q++;
    }
  }
  return p1 + p2 - ans * 2;
}
void solve() {
  long long n, ans = 1e16;
  cin >> n;
  for (int i = 0; i <= 62; i++) {
    ans = min(ans, doit(n, i));
  }
  cout << ans << endl;
}
int main(void) {
  init();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
