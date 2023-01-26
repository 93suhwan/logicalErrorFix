#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string alphabets, str;
    cin >> alphabets >> str;
    int ans = 0;
    if (str.length() == 0) {
      cout << ans << endl;
    }
    for (int i = 0; i < str.length() - 1; i++) {
      ans += abs(int((str[i] - 'a' + 1)) - ((str[i + 1] - 'a' + 1)));
    }
    cout << ans << endl;
  }
  return 0;
}
