#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s[100];
  cin >> n;
  while (n--) {
    int length, count;
    cin >> length;
    count = (length - 2) * 2 - length;
    for (int i = 0; i < length - 2; i++) {
      cin >> s[i];
    }
    string ans;
    for (int i = 0; i < length - 2; i++) {
      if (i == 0)
        ans += s[i];
      else if (i > 0 && count > 0) {
        if (s[i][0] == s[i - 1][1]) {
          ans += s[i][1];
          count--;
        } else {
          ans += s[i];
        }
      } else {
        ans += s[i];
      }
    }
    if (count < 0) {
      while (count < 0) {
        ans = 'b' + ans;
        count++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
