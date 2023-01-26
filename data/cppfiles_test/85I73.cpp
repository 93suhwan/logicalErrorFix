#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int ans = 0;
    if (str.find("1") == -1) {
      ans = 1;
    } else if (str.find("0") == -1) {
      ans = 0;
    } else {
      for (int i = 0; str[i]; i++) {
        if (str[i] == '0') {
          ans++;
          for (int j = i + 1; str[j]; j++) {
            if (str[j] != str[i]) {
              i = j - 1;
            }
          }
        }
        if (ans >= 2) break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
