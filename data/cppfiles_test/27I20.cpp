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
      cout << (m == 0 && k > 0 ? "YES" : "NO") << '\n';
      continue;
    }
    if (n == 2) {
      cout << (m == 1 && k > 1 ? "YES" : "NO") << '\n';
      continue;
    }
    int d = 2;
    long long maxm = n * (n - 1) / 2;
    if (m > maxm) {
      cout << "NO\n";
      continue;
    }
    if (m == maxm) {
      d = 1;
    }
    cout << (d < k - 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}
