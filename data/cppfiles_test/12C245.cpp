#include <bits/stdc++.h>
using namespace std;
void solve_test(int tc) {
  int n, m, k;
  cin >> n >> m >> k;
  if (m % 2 == 0) {
    if (n % 2 == 0) {
      cout << (k % 2 == 0 ? "YES" : "NO") << '\n';
    } else {
      if (k < m / 2) {
        cout << "NO\n";
        return;
      }
      k -= m / 2;
      cout << (k % 2 == 0 ? "YES" : "NO") << '\n';
    }
  } else {
    if (n % 2 == 0) {
      cout << ((k % 2 == 0 && k <= (m - 1) * n / 2) ? "YES" : "NO") << '\n';
    } else {
      assert(false);
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve_test(i);
  }
}
