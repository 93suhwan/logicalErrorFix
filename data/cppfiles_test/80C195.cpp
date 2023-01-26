#include <bits/stdc++.h>
using namespace std;
char s[200010];
int main() {
  int t;
  cin >> t;
  int flag = 0;
  while (t--) {
    int l;
    cin >> l;
    for (int i = 1; i <= l; i++) {
      cin >> s[i];
    }
    int mid = l / 2;
    for (int i = 1; i <= l; i++) {
      if (s[i] == '0') {
        if (i > mid) {
          cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
          flag = 1;
          break;
        } else {
          cout << i << " " << l << " " << i + 1 << " " << l << endl;
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
