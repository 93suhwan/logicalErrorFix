#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long ans1 = 10, ans2 = 10;
    long long g1 = 0, g2 = 0;
    long long l1 = 5, l2 = 5;
    string s;
    cin >> s;
    for (long long i = 0; i < s.length(); i++) {
      if (i % 2 == 0 && s[i] == '1') {
        g1++;
      }
      if (i % 2 == 0) {
        l1--;
      } else if (i % 2 == 1 && s[i] != '0') {
        g2++;
      }
      if ((g2 - g1) > l1) {
        ans1 = i + 1;
        break;
      }
    }
    g1 = 0;
    g2 = 0;
    for (long long i = 0; i < s.length(); i++) {
      if (i % 2 == 1 && s[i] == '1') {
        g1++;
      } else if (i % 2 == 0 && s[i] != '0') {
        g2++;
      }
      if (i % 2 == 1) {
        l2--;
      }
      if ((g2 - g1) > l2) {
        ans2 = i + 1;
        break;
      }
    }
    cout << min(ans1, ans2) << "\n";
  }
  return 0;
}
