#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int otv = 0, flag = 0;
  int pov = 0;
  string a;
  cin >> t;
  for (int i = 0; i < t; i++) {
    otv = 0;
    pov = 0;
    cin >> a;
    for (int j = 0; a[j] != '\0'; j++) {
      flag = 0;
      for (int k = j + 1; a[k] != '\0'; k++) {
        if (a[j] == a[k]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        pov++;
      else
        otv++;
    }
    if (pov != 0) {
      otv--;
      pov++;
    }
    if (pov >= 2 && otv >= 2) {
      cout << otv / 2 + pov / 2 << endl;
    } else {
      if (pov == 0) {
        cout << otv / 2 << endl;
      }
    }
    if (otv == 0 && pov >= 2) cout << 1 << endl;
  }
}
