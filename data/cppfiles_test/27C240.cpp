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
    long long maxm = n * (n - 1) / 2;
    if (m < n - 1 || m > maxm) {
      cout << "NO\n";
      continue;
    }
    if (n == 1) {
      cout << (k > 1 ? "YES" : "NO") << '\n';
      continue;
    }
    if (m == maxm) {
      cout << (k > 2 ? "YES" : "NO") << '\n';
      continue;
    }
    cout << (k > 3 ? "YES" : "NO") << '\n';
  }
  return 0;
}
