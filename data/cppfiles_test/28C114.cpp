#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  long long int s = (a + b * 2 + c * 3);
  cout << (s & 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
