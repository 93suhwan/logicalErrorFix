#include <bits/stdc++.h>
using namespace std;
void runCase(const int TC) {
  int l, r;
  cin >> l >> r;
  int li = l, ri = r, ans = r % l;
  while (li <= ri) {
    int mid = li + (ri - li) / 2;
    if (mid * 2 - 1 <= r)
      ans = mid - 1, li = mid + 1;
    else
      ri = mid - 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) runCase(tc);
  cout << "TEST"
       << "\n";
  return 0;
}
