#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s[100];
  cin >> n;
  while (n--) {
    int length, count = 2;
    cin >> length;
    for (int i = 0; i < length - 2; i++) {
      cin >> s[i];
    }
    string ans;
    for (int i = 0; i < length - 2; i++) {
      if (i == 0)
        ans += s[i];
      else if (i > 0) {
        if (s[i][0] == s[i - 1][1]) {
          ans += s[i][1];
          count--;
        } else {
          ans += s[i];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
