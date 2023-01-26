#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long int> v[65];
void solve() {
  unsigned long long int l, r;
  cin >> l >> r;
  unsigned long long int p = r - l;
  if (p == 0) {
    cout << 0 << endl;
  } else if (p < l) {
    cout << p << endl;
  } else {
    unsigned long long int x = (p - l + 1) / 2;
    cout << l + x - 1 << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  unsigned long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
