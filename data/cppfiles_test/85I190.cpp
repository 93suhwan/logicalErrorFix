#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ll one = 0;
    ll zer = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        zer++;
      } else {
        one++;
      }
    }
    if (zer == 0) {
      int ans = 0;
      cout << ans << "\n";
      continue;
    }
    if (one == 0) {
      int ans = 1;
      cout << ans << "\n";
      continue;
    }
    if (zer == 1) {
      cout << 1 << "\n";
      continue;
    }
    if (one != 0 && zer > 1) {
      char a = s[0];
      int j = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != a) {
          j = i;
        }
      }
      char b = s[j];
      bool flag = false;
      for (int i = j; i < s.size(); i++) {
        if (s[i] != b) {
          flag = true;
          break;
        }
      }
      if (flag == false) {
        cout << 1 << "\n";
        continue;
      } else {
        cout << 2 << "\n";
        continue;
      }
    }
  }
  return 0;
}
