#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
const int N = 3e5 + 9;
const int mod = 998244353;
const int moh = 1e9 + 3;
const int base = 311;
const int oi = 2e9;
const long long oo = 1e18;
const double eps = 1e-9;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int n, k;
pair<int, int> a[N];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  int d = 1;
  a[1].second = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i].first < a[i - 1].first) {
      d++;
    }
    a[i].second = d;
  }
  sort(a + 1, a + n + 1);
  int z = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i].second - a[i - 1].second) {
      z++;
    }
  }
  if (z <= k) {
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
