#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  int a = sqrt(n);
  int b = cbrt(n);
  int c = sqrt(b);
  cout << a + b - c << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int TC;
  cin >> TC;
  while (TC--) solve();
  return 0;
}
