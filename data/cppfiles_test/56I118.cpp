#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool flag = 1;
    for (int i = 1; i <= 8; i++) {
      if (!flag) {
        break;
      }
      for (int j = 1; j <= 8; j++) {
        cout << i << " " << (i & 1 ? j : 9 - j) << endl;
        cout.flush();
        string s;
        cin >> s;
        if (s == "Done") {
          flag = 0;
          break;
        }
      }
    }
  }
}
