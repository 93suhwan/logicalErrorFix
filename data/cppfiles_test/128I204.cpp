#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 3; i < 8; i += 2) {
    if (gcd(i, n - 1 - i) == 1) {
      cout << i << " " << n - 1 - i << " " << 1 << endl;
      break;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
