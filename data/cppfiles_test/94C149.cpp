#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long n1 = 0, n2 = 0, p1 = 1, p2 = 1;
  for (int i = 0; n != 0; n /= 10, i++) {
    if (i % 2) {
      n1 = n1 + p1 * (n % 10);
      p1 *= 10;
    } else {
      n2 = n2 + p2 * (n % 10);
      p2 *= 10;
    }
  }
  cout << (n1 + 1) * (n2 + 1) - 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
