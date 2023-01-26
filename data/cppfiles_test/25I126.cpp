#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, k, A;
  string s, c;
  cin >> n;
  while (n--) {
    cin >> s;
    cin >> c;
    for (int i = 0; i < s.length(); i++) {
      k = 0;
      A = i;
      count = 0;
      if (c[k] == s[i]) {
        while (c[k] == s[i] && i < s.length() && k < c.length()) {
          count++;
          k++;
          i++;
        }
        i -= 2;
        while (c[k] == s[i] && i >= 0 && k < c.length()) {
          count++;
          k++;
          i--;
        }
      }
      if (count == c.length()) {
        break;
      }
      i = A;
    }
    if (count == c.length()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
