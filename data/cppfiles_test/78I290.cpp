#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int l, r;
  cin >> l >> r;
  if (r % 2 == 1) r++;
  long long int mid = r / 2;
  if (l > mid)
    cout << r % l << endl;
  else {
    r--;
    cout << r % mid << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
