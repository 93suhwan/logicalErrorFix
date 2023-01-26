#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int c = 0;
    string p;
    cin >> p;
    int l = p.length();
    if (l % 2 != 0)
      cout << "NO" << endl;
    else {
      for (int i = 0; i < l / 2; i++) {
        if (p[i] == p[(l / 2) + i]) {
          c++;
        }
      }
      if (c == l / 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
