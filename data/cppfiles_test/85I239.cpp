#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int num0 = 0, num1 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0')
        num0++;
      else
        num1++;
    }
    int ans;
    if (!num0 && num1)
      ans = 0;
    else if (!num1 && num0)
      ans = 1;
    else if (num0 >= 2)
      ans = 2;
    else {
      ans = num0;
    }
    cout << ans << endl;
  }
  return 0;
}
