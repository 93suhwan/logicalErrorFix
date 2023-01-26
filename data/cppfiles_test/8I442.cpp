#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << ' ' << 0 << endl;
    return;
  } else if (n % 3 == 0) {
    cout << n / 3 << ' ' << n / 3 << endl;
    return;
  } else if (n % 10 == 2) {
    cout << n / 3 << ' ' << (n - n / 3) / 2 << endl;
  } else if (n % 2 == 0) {
    cout << n / 3 + 1 << ' ' << (n - (n / 3 + 1)) / 2 << endl;
    return;
  } else if (n % 2 == 1) {
    cout << n / 3 << ' ' << (n - n / 3) / 2 << endl;
    return;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
