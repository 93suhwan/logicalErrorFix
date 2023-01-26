#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long MOD = 1000000007;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  k--;
  int fully = n * (n - 1) / 2;
  int mn = n - 1;
  if (m < mn || m > fully) {
    cout << "NO";
  } else if (n == 1) {
    if (m == 0 && k > 0)
      cout << "YES";
    else
      cout << "NO";
  } else if (m == fully) {
    if (k > 1)
      cout << "YES";
    else
      cout << "NO";
  } else {
    if (k > 2)
      cout << "YES";
    else
      cout << "NO";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
    cout << '\n';
  }
}
