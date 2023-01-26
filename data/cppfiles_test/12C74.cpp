#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 1) {
    int u = m / 2;
    if (k >= u) {
      k -= u;
      if (k % 2 == 0) {
        cout << "YES\n";
        return;
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
      return;
    }
  } else if (m % 2 == 1) {
    int u = n / 2;
    k = ((n * m) / 2) - k;
    if (k >= u) {
      k -= u;
      if (k % 2 == 0) {
        cout << "YES\n";
        return;
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
      return;
    }
  } else {
    if (k % 2 == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
