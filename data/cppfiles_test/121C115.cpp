#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string c;
    string d;
    cin >> n;
    cin >> c;
    cin >> d;
    if (c == d) {
      cout << 0 << endl;
      continue;
    }
    long long cnt1 = count(c.begin(), c.end(), '1');
    if (cnt1 == 0) {
      cout << "-1" << endl;
      continue;
    }
    long long cnt0 = 0;
    cnt1 = 0;
    long long cnt01 = 0;
    long long cnt10 = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] == d[i] && c[i] == '1') {
        cnt1++;
      } else if (c[i] == d[i] && c[i] == '0') {
        cnt0++;
      } else if (c[i] == '0' && d[i] == '1') {
        cnt01++;
      } else {
        cnt10++;
      }
    }
    long long ans = 0x7fffffffffffffff;
    if (cnt01 == cnt10) {
      ans = cnt01 + cnt10;
    }
    if (cnt1 - cnt0 == 1) {
      ans = min(cnt1 + cnt0, ans);
    }
    if (ans == 0x7fffffffffffffff) {
      cout << "-1" << endl;
    } else
      cout << ans << endl;
  }
  return 0;
}
