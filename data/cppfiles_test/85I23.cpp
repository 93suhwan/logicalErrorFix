#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    if (zero == n)
      cout << 1 << endl;
    else if (one == n)
      cout << 0 << endl;
    else if (zero >= 2)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
}
