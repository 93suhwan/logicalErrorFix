#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int conti_0 = 0;
    int conti_1 = 0;
    int conti_2 = 0;
    char prev = s[0];
    map<char, int> mp;
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == '0') {
        conti_0++;
        if (prev == '1') {
          ans += 0;
        }
        prev = s[i];
      }
      if (s[i] == '1') {
        conti_1++;
        if (prev == '0') {
          ans += 1;
        }
        prev = s[i];
      }
      if (s[i] == '2') {
        conti_2++;
        if (prev == '0') {
          ans += 1;
        }
        prev = s[i];
      }
    }
    if (prev == '0') ans += 1;
    if (ans > 2) ans = 2;
    cout << ans << endl;
  }
}
