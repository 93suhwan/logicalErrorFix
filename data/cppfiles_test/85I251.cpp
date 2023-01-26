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
    int ad = 0;
    for (int i = 0; i < n - 1; i++)
      if (s[i] == s[i + 1] == '0') ad++;
    if (zero == n)
      cout << 1 << endl;
    else if (one == n)
      cout << 0 << endl;
    else if (ad + 1 == zero)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
