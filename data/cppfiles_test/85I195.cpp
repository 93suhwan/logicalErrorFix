#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int no1 = 0, no0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        no1++;
      else
        no0++;
    }
    if (no1 == 0)
      cout << 1 << "\n";
    else {
      if (no0 <= 2)
        cout << no0 << "\n";
      else
        cout << 2 << "\n";
    }
  }
  return 0;
}
