#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 2e5 + 5, M = 2e5 + 5;
int n, m, k;
void solve() {
  cin >> n >> m >> k;
  if (k <= m / 2 * n) {
    if (k % 2 == 0 and n % 2 == 0)
      cout << "YES\n";
    else if (k % 2 == 0 and n & 1 and 2 * k % m == 0 and 2 * k / m % 2 == 1)
      cout << "YES\n";
    else if (k & 1 and n & 1 and k * 2 % m == 0 and k * 2 / m % 2 == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
