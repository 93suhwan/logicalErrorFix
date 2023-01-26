#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long r, c;
  cin >> r;
  cin >> c;
  long long ans = 0;
  long long z = max(r, c);
  long long z2 = (z - 1) * (z - 1);
  if (z % 2 == 0) {
    if (z == c) {
      ans = z2 + r;
    } else {
      ans = z2 + 2 * z - c;
    }
  } else {
    if (r == z) {
      ans = z2 + c;
    } else {
      ans = z2 + 2 * z - r;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
