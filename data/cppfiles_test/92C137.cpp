#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (long long tc = 0; tc < t; tc++) {
    string str;
    cin >> str;
    long long cnt_ab = 0, cnt_ba = 0;
    for (long long i = 0; i + 1 < (long long)str.size(); i++) {
      cnt_ab += (str[i] == 'a' && str[i + 1] == 'b');
      cnt_ba += (str[i] == 'b' && str[i + 1] == 'a');
    }
    if (cnt_ab == cnt_ba) {
      cout << str << "\n";
      continue;
    }
    if (cnt_ab > cnt_ba) {
      for (long long i = 0; i + 1 < (long long)str.size(); i++) {
        if (str[i] == 'a') {
          str[i] = 'b';
          break;
        }
      }
    } else {
      for (long long i = 0; i + 1 < (long long)str.size(); i++) {
        if (str[i] == 'b') {
          str[i] = 'a';
          break;
        }
      }
    }
    cout << str << "\n";
  }
  return 0;
}
