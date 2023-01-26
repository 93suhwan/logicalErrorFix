#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 2; i < n - 1; i++)
    if (gcd(i, n - 1) == 1) {
      cout << i << " " << n - 1 - i << " " << 1;
      return;
    }
  cout << "WALAWALA";
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
    cout << "\n";
  }
}
