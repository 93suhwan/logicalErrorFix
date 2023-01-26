#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string str;
    cin >> str;
    bool good = false;
    char goodch;
    bool two = false;
    for (int i = k - 1; i >= 0; i--) {
      if (str[i] == '4' || str[i] == '9' || str[i] == '6' || str[i] == '8') {
        good = true;
        goodch = str[i];
        break;
      }
    }
    if (good) {
      cout << 1 << "\n" << goodch << endl;
      continue;
    }
    int val = 0;
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        val = (str[i] - '0') * 10 + (str[j] - '0');
        for (int d = 2; d <= 9; d++) {
          if (val % d == 0) {
            good = true;
            break;
          }
        }
        if (good) break;
      }
      if (good) break;
    }
    cout << 2 << endl;
    cout << val << endl;
  }
  return 0;
}
