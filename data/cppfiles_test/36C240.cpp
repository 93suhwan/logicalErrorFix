#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1) {
      cout << "a" << endl;
      continue;
    }
    if (n == 2) {
      cout << "ab" << endl;
      continue;
    }
    if (n == 3) {
      cout << "abc" << endl;
      continue;
    }
    int tmp = n / 2;
    string ans;
    string cur1 = "";
    string cur2 = "";
    for (int i = 1; i <= tmp; i++) {
      cur1 += "a";
    }
    for (int i = 1; i <= tmp - 1; i++) {
      cur2 += "a";
    }
    if (n & 1) {
      ans = cur1 + "bc" + cur2;
    } else {
      ans = cur1 + "b" + cur2;
    }
    cout << ans << endl;
  }
  return 0;
}
