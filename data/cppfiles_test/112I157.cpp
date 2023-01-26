#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long a[3], m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a, a + 3);
    long long mn = max({0ll, a[2] - a[0] - a[1], a[0] + a[1] - a[2] - 1});
    long long mx = a[0] + a[1] + a[2] - 3;
    if (m >= mn && m <= mx)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
