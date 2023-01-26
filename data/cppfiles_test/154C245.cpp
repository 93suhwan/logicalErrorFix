#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout.precision(15);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if (a[2] == a[0] + a[1]) {
      cout << "YES" << '\n';
      continue;
    }
    if ((a[0] == a[1] && a[2] % 2 == 0) || (a[1] == a[2] && a[0] % 2 == 0)) {
      cout << "YES" << '\n';
      continue;
    }
    cout << "NO" << '\n';
  }
  return 0;
}
