#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m % 2) {
    swap(n, m);
    k = n * m / 2 - k;
  }
  if (!(n % 2)) {
    if (!(k % 2)) {
      cout << "YES"
           << "\n";
      return;
    }
    cout << "NO"
         << "\n";
    return;
    return;
  } else {
    k -= m / 2;
    if (k < 0) {
      cout << "NO"
           << "\n";
      return;
    }
    if (!(k % 2)) {
      cout << "YES"
           << "\n";
      return;
    }
    cout << "NO"
         << "\n";
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
