#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  cout << (a + (b * 2) + (c * 3)) % 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
