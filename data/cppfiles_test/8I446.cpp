#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a = n / 3;
  int b = (n - a) / 2;
  cout << a << ' ' << b;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
  }
  return 0;
}
