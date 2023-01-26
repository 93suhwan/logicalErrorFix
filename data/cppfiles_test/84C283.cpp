#include <bits/stdc++.h>
using namespace std;
int T, a, b;
void solve() {
  cin >> a >> b;
  int t = a / 2 + 1;
  cout << b / t;
}
int main() {
  cin >> T;
  while (T--) {
    solve();
    if (T != 0) {
      cout << "\n";
    }
  }
  return 0;
}
