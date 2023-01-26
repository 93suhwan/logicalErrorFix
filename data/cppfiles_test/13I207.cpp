#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() <= 3) {
      cout << "NO" << endl;
    } else {
      long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
      for (long long i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
          cnt1++;
        } else if (s[i] == 'B') {
          cnt2++;
        } else {
          cnt3++;
        }
      }
      if (cnt1 != 0 && cnt2 != 0 && cnt3 != 0) {
        if (cnt1 == cnt2 && cnt2 == cnt3) {
          cout << "YES" << endl;
        } else {
          if (cnt1 + cnt3 == cnt2) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        }
      } else if (cnt1 != 0 && cnt2 != 0 && cnt3 == 0) {
        if (cnt1 == cnt2) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else if (cnt2 != 0 && cnt3 != 0 && cnt1 == 0) {
        if (cnt2 == cnt3) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
