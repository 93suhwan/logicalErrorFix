#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], n;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n & 1) {
    if (a[1] + a[2] != 0) {
      cout << a[3] << ' ' << a[3] << ' ' << -(a[1] + a[2]) << ' ';
    } else if (a[1] + a[3] != 0) {
      cout << a[2] << ' ' << a[2] << ' ' << -(a[1] + a[3]) << ' ';
    } else {
      cout << a[1] << ' ' << a[1] << ' ' << -(a[2] + a[3]) << ' ';
    }
    int p = 4;
    while (p <= n) {
      cout << a[p + 1] << ' ' << -a[p] << ' ';
      p += 2;
    }
    cout << '\n';
  } else {
    for (int i = 1; i <= n; i += 2) {
      cout << a[i + 1] << ' ' << -a[i] << ' ';
    }
    cout << '\n';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
