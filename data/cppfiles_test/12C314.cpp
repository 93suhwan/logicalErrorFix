#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int min_h = n % 2 ? m / 2 : 0;
    int max_h = n * m / 2 - (m % 2 ? n / 2 : 0);
    if (min_h <= k && k <= max_h && (k - min_h) % 2 == 0) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
