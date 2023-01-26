#include <bits/stdc++.h>
using namespace std;
int n, m, k;
void solve() {
  if (n % 2 == 1 && m % 2 == 0) {
    if (k < m / 2) {
      cout << "NO" << endl;
      return;
    }
    k -= m / 2;
    if (k % 2 == 1) {
      cout << "NO" << endl;
      return;
    }
  }
  if (m % 2 == 1 && k == n * m / 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    solve();
  }
}
