#include <bits/stdc++.h>
using namespace std;
void Ok() {
  long int a[100013], b, c, d, e, f, g, h, t, i, j, k, l, m, n, Mn, Mx;
  long int ans1, ans2, ans3, cnt1, cnt2, cnt3, flag1, flag2, flag3, temp, sum;
  double aa, bb, cc, dd, ee, ff, gg;
  char aaa, bbb, ccc, ddd;
  string spc, in, keyword;
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    Mx = 0;
    for (i = 1; i < n; i++) {
      ans1 = a[i] * a[i + 1];
      Mx = max(Mx, ans1);
    }
    cout << Mx << '\n';
  }
  return;
}
int main() {
  Ok();
  return 0;
}
