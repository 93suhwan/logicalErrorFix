#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
    return;
  }
  if (n % 2 == 0 && m % 2 == 1) {
    if (k % 2 == 0 && k <= (n * (m - 1)) / 2)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
    return;
  }
  if (n % 2 == 1 && m % 2 == 0) {
    if (k >= m / 2) {
      k -= m / 2;
      n -= 1;
    } else {
      cout << "NO" << '\n';
      return;
    }
    if (k % 2 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
