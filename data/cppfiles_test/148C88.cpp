#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long k, max1 = 0, max2 = 0;
  for (int j = 1; j <= 4; j++) {
    cin >> k;
    long long l, r;
    for (long long i = 1; i <= k; i++) {
      long long x;
      cin >> x;
      if (i == 1) l = x;
      if (i == k) r = x;
    }
    if (j == 1 || j == 2) max1 = max(r - l, max1);
    if (j == 3 || j == 4) max2 = max(max2, r - l);
  }
  if (max1 * h > max2 * w)
    cout << (long long)max1 * h << endl;
  else
    cout << (long long)max2 * w << endl;
}
int main() {
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
