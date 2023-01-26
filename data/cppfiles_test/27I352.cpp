#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    if (k > 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (n < m - 1) {
    cout << "NO" << endl;
  } else if (n == m - 1) {
    if (k > 2) {
      cout << "NO" << endl;
    }
    cout << "YES" << endl;
  } else if (m > (n * (n - 1)) / 2) {
    cout << "NO" << endl << "m > n*n-1/2" << endl;
  } else if (m == (n * (n - 1)) / 2) {
    if (k > 2) {
      cout << "YES";
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
