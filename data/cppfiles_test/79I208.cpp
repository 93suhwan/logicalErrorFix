#include <bits/stdc++.h>
using namespace std;
int x, n;
string s;
char l[20] = {'2', '2', '2', '3', '3', '3', '5', '5', '7', '7', '7'};
char r[20] = {'2', '5', '7', '2', '3', '5', '2', '5', '2', '5', '7'};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    bool b = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
          s[i] == '9') {
        b = 0;
        cout << 1 << '\n' << s[i] << '\n';
        break;
      }
    }
    int j = 0;
    while (b) {
      char ll = l[j];
      char rr = r[j];
      bool bl = 0, br = 0;
      int i = 0;
      for (; i < s.size(); i++) {
        if (s[i] == ll) {
          bl = 1;
          i++;
          break;
        }
      }
      for (; i < s.size(); i++)
        if (s[i] == rr) {
          br = 1;
          break;
        }
      if (bl && br) {
        b = 0;
        cout << 2 << '\n' << ll << rr << '\n';
      }
      j++;
    }
  }
}
