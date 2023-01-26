#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
const int N = 2e5 + 9;
const int mod = 998244353;
const int moh = 1e9 + 3;
const int base = 311;
const int oi = 2e9;
const long long oo = 1e18;
const double eps = 1e-9;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int n, a[N], k;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int d = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      d++;
    }
  }
  if (d <= k) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
