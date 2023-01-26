#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int mid;
  if (r % 2 == 0)
    mid = r / 2;
  else
    mid = (r + 1) / 2;
  if (l > mid)
    cout << r % l << endl;
  else {
    if (r % 2 == 0) r--;
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
