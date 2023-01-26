#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, ca = 0, cb = 0;
    bool flag = false;
    cin >> n;
    string str;
    cin >> str;
    if (n == 1) {
      cout << "-1"
           << " "
           << "-1"
           << "\n";
    } else {
      for (int i = 0; i < n - 1; i++) {
        if (str[i] != str[i + 1]) {
          cout << i + 1 << " " << i + 2 << "\n";
          break;
          flag = true;
        }
      }
      if (flag == false) {
        cout << "-1"
             << " "
             << "-1"
             << "\n";
      }
    }
  }
}
