#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  cout << (int)sqrt(n) + cbrt(n) - cbrt(sqrt(n)) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
