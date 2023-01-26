#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1 && b == 2) {
    cout << 1 << endl;
    return;
  }
  int x = 1;
  while (x * 2 < b) {
    x *= 2;
  }
  cout << x - a << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
