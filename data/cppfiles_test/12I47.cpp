#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int b = (n * m) / 2;
  if (n % 2 == 0 and m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (n % 2 != 0) {
    if (b != k) {
      cout << "NO" << endl;
    } else if (k % 2 == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else {
    if (m == 1 and k != 0) {
      cout << "NO" << endl;
    } else if (k % 2 != 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
