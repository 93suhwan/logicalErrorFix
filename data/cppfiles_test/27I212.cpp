#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n < m - 1) {
    cout << "NO" << endl;
  } else if (m > (n * (n - 1)) / 2) {
    cout << "NO";
  } else if (m == (n * (n - 1)) / 2) {
    if (k > 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (n == 1) {
    if (k > 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (m == n - 1) {
    if (k > 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  cout.sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
