#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int hash[10] = {0};
    bool flag1 = 0, flag7 = 0, flag1_final = 0, flag7_final = 0;
    int i = 0;
    string ans;
    for (i = 0; i < n; i++) {
      int num = str[i] - 48;
      if (num == 4 || num == 6 || num == 8 || num == 9 || num == 1) {
        ans = to_string(num);
        break;
      }
      hash[num]++;
      if (i != 0 && (num == 2 || num == 5)) {
        ans = to_string((str[0] - 48) * 10 + num);
      }
      if (num == 2) flag7 = 2;
      if (flag7 != 0 && num == 7) {
        flag7_final = 1;
        ans = to_string(20 + num);
      }
    }
    if (i == n || ans.length() != 1) {
      for (int i = 1; i <= 9; i++) {
        if (hash[i] > 1) {
          ans = to_string(10 * i + i);
          break;
        }
      }
    }
    if (i == n && ans.length() == 0) ans = str;
    int count = ans.length();
    cout << count << "\n";
    cout << ans << "\n";
  }
}
