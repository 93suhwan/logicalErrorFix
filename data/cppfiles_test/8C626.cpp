#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << ' ' << 0 << endl;
    return;
  }
  if (n % 3 == 0) {
    cout << n / 3 << ' ' << n / 3 << endl;
    return;
  }
  if ((n - (n / 3)) % 2 == 0) {
    cout << n / 3 << ' ' << (n - (n / 3)) / 2 << endl;
    return;
  } else if ((n - (n / 3)) % 2 == 1) {
    cout << n / 3 + 1 << ' ' << (n - (n / 3 + 1)) / 2 << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
