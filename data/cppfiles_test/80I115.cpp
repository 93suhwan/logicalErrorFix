#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int flag = 1;
    for (char ch : str) {
      if (ch == '0') {
        flag = 0;
      }
    }
    if (flag) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
      break;
    }
    for (int i = 0; i < n; i++) {
      if (str[i] == '0') {
        if (i < n / 2) {
          cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
          ;
          break;
        } else if (i >= n / 2) {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
          ;
          break;
        }
      }
    }
  }
}
