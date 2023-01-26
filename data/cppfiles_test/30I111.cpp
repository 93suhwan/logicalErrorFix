#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = true;
    long long lo = 0, hi = n - 1;
    while (lo <= hi) {
      if (s[lo] != s[hi]) {
        flag = false;
        break;
      } else {
        lo++;
        hi--;
      }
    }
    if (flag)
      cout << 0 << '\n';
    else {
      long long mini = INT_MAX;
      char ch1 = s[0];
      long long dele1 = 0;
      char ch2 = s[n - 1];
      long long dele2 = 0;
      bool ok1 = true;
      long long lo1 = 0, hi1 = n - 1;
      while (lo1 <= hi1) {
        if (s[lo1] != s[hi1]) {
          if (s[lo1] == ch1) {
            lo1++;
            dele1++;
          } else if (s[hi1] == ch1) {
            hi1--;
            dele1++;
          } else {
            ok1 = false;
            break;
          }
        } else {
          lo1++;
          hi1--;
        }
      }
      bool ok2 = true;
      long long lo2 = 0, hi2 = n - 1;
      while (lo2 <= hi2) {
        if (s[lo2] != s[hi2]) {
          if (s[lo2] == ch2) {
            lo2++;
            dele2++;
          } else if (s[hi2] == ch2) {
            hi2--;
            dele2++;
          } else {
            ok2 = false;
            break;
          }
        } else {
          lo2++;
          hi2--;
        }
      }
      if (ok1 == false && ok2 == false)
        cout << -1 << '\n';
      else if (ok2 == false && ok1 == true)
        cout << dele1 << '\n';
      else if (ok1 == false && ok2 == true)
        cout << dele2 << '\n';
      else
        cout << min(dele1, dele2) << '\n';
    }
  }
}
