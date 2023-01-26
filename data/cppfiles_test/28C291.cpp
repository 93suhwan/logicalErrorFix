#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, a, b, c, ans;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if ((a + c) % 2 == 0)
      ans = 0;
    else
      ans = 1;
    cout << ans << endl;
  }
  return 0;
}
