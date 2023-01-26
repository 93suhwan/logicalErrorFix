#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1) {
      cout << "NO\n";
      continue;
    }
    if (n == 1) {
      cout << (k > 0 ? "YES" : "NO") << '\n';
      continue;
    }
    if (n == 2) {
      cout << (m == 1 && k > 1 ? "YES" : "NO") << '\n';
      continue;
    }
    int d = 2;
    int maxd = n * (n - 1) / 2;
    if (m > maxd) {
      cout << "NO\n";
      continue;
    }
    if (m == maxd) {
      d = 1;
    }
    cout << (d < k - 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}
