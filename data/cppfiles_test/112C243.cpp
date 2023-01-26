#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int aa, b, c, m;
  cin >> aa >> b >> c >> m;
  vector<int> a = {aa, b, c};
  sort(a.rbegin(), a.rend());
  int lower_bound = a[0] - a[1] - a[2] - 1;
  int upper_bound = aa + b + c - 3;
  if (m >= lower_bound && m <= upper_bound) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
