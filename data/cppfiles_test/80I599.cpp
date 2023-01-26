#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int flag = 0;
  while (t--) {
    int l;
    cin >> l;
    string s;
    cin >> s;
    int mid = l / 2;
    for (int i = 0; i < l; i++) {
      if (s[i] == '0') {
        if (i > mid) {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
          flag = 1;
          break;
        } else {
          cout << i + 1 << " " << l << " " << i + 2 << " " << l << endl;
          flag = 1;
          break;
        }
      }
    }
    if (!flag) {
      cout << 1 << " " << l - 1 << " " << 2 << " " << l << endl;
    }
    flag = 0;
  }
  return 0;
}
