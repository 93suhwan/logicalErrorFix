#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int u = 0;
    int v = 0;
    for (int i = 0; i < s.length(); i++) {
      if (i % 2 == 0) {
        if (s[i] == '1') {
          u++;
        } else if (s[i] == '?') {
          if (i == 0 || u >= v) {
            u++;
          }
        }
      } else {
        if (s[i] == '1') {
          v++;
        } else if (s[i] == '?') {
          if (v >= u) {
            v++;
          }
        }
      }
      int k1 = (9 - i) / 2;
      int k2 = (10 - i) / 2;
      if ((u > v && k2 < (u - v)) || i == 9) {
        cout << i + 1 << endl;
        break;
      } else if ((v > u && k1 < (v - u)) || i == 9) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
