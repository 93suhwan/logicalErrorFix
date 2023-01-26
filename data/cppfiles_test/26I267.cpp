#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    string s, t;
    vector<long long> v;
    cin >> s;
    int fir = 0, sec = 0, flag = 0, flagg = 0;
    int firr = 0, secc = 0;
    for (int i = 1; i <= 10; i++) {
      if (i % 2 == 1) {
        if (s[i - 1] != '0') fir++;
      } else {
        if (s[i - 1] == '1') sec++;
      }
      if (fir > sec + (10 - i + 1) / 2) {
        flag = i;
        break;
      }
    }
    for (int i = 1; i <= 10; i++) {
      if (i % 2 == 1) {
        if (s[i - 1] == '1') firr++;
      } else {
        if (s[i - 1] != '0') secc++;
      }
      if (secc > firr + (10 - i) / 2) {
        flagg = i;
        break;
      }
    }
    if (flag && flagg)
      cout << min(flag, flagg) << endl;
    else
      cout << max(flag, flagg) << endl;
  }
  return 0;
}
