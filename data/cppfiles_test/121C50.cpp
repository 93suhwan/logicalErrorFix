#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long int a10 = 0, a01 = 0, a00 = 0, a11 = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == '1') {
          a11++;
        } else {
          a00++;
        }
      } else {
        if (a[i] == '1') {
          a10++;
        } else {
          a01++;
        }
      }
    }
    long long int ans1 = 0, ans2 = 0;
    if (a01 == a10) {
      ans1 = 2 * a01;
    } else {
      ans1 = -1;
    }
    if (a11 - 1 == a00) {
      ans2 = a11 + a00;
    } else {
      ans2 = -1;
    }
    long long int ans;
    if (ans2 == -1 and ans1 == -1) {
      ans = -1;
    } else if (ans2 == -1) {
      ans = ans1;
    } else if (ans1 == -1) {
      ans = ans2;
    } else {
      ans = min(ans2, ans1);
    }
    cout << ans << endl;
  }
  return 0;
}
