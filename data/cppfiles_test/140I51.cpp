#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  float a = sqrt(n);
  float b = cbrt(n);
  int c = 1;
  for (int i = 2; i < 32; i++) {
    long long int k = pow(i, 6);
    if (k < n) c++;
  }
  if (n == 999999999) c++;
  a = int(a);
  b = int(b);
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
