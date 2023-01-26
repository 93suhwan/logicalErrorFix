#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt1, cnt2, cnt3, cnt4;
    cnt1 = cnt2 = cnt3 = cnt4 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == '0') {
          cnt1++;
        } else {
          cnt2++;
        }
      } else {
        if (a[i] == '0') {
          cnt3++;
        } else {
          cnt4++;
        }
      }
    }
    int ans = n + 1;
    if (cnt1 + cnt2 == n) {
      ans = 0;
    }
    if ((cnt1 == cnt2 && cnt1) || cnt1 + 1 == cnt2) {
      ans = min(ans, cnt1 + cnt2);
    }
    if ((cnt3 == cnt4 && cnt3) || cnt3 + 1 == cnt4) {
      ans = min(ans, cnt3 + cnt4);
    }
    ans = ans == n + 1 ? -1 : ans;
    cout << ans << '\n';
  }
  return 0;
}
