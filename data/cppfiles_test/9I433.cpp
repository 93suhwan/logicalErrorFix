#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    string s;
    cin >> s;
    long long c1 = 0, c2 = 0, k = 0;
    int len = s.length();
    if (len == 1) {
      cout << 0;
    } else {
      int count[MAX_CHAR];
      for (int i = 0; i < MAX_CHAR; i++) {
        count[i] = 0;
      }
      for (int i = 0; i < len; i++) {
        char x = s[i];
        ++count[x];
      }
      for (int i = 0; i < MAX_CHAR; i++) {
        if (count[i] == 1) {
          c1++;
        } else if (count[i] > 1) {
          c2++;
        }
      }
      if (c1 % 2 == 0) {
        k = c1 / 2;
      } else {
        k = (c1 - 1) / 2;
      }
      k += c2;
      cout << k;
    }
    cout << "\n";
  }
  return 0;
}
