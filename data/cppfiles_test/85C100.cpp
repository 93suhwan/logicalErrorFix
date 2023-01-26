#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int y;
  cin >> y;
  while (y--) {
    string s;
    cin >> s;
    int o = 0, z = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0')
        z++;
      else
        o++;
    }
    if (o == 0)
      cout << 1 << endl;
    else if (z == 0)
      cout << 0 << endl;
    else {
      if (z == 1)
        cout << 1 << endl;
      else {
        int c = 0, d = 0;
        for (int i = 0; i < s.length(); i++) {
          if (s[i] == '0')
            c = 1;
          else {
            if (c > 0) d += 1;
            c = 0;
          }
        }
        if (c + d >= 2)
          cout << 2 << endl;
        else
          cout << 1 << endl;
      }
    }
  }
}
