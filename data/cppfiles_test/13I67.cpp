#include <bits/stdc++.h>
using namespace std;
bool possible_erase(string &str) {
  short a(0), b(0), c(0);
  for (auto i : str) {
    (i == 'B') ? b += 1 : b;
    (i == 'A') ? a += 1 : a;
    (i == 'C') ? c += 1 : c;
  }
  return (b == a + c);
}
int main() {
  short t;
  cout << "Enter the number of test cases, ranging from 1 to 1000:" << endl;
  cin >> t;
  while ((t < 1) || (t > 1000)) {
    cout << "The entered value is out-ranged, pls re-enter:" << endl;
    cin >> t;
  }
  cout << t << endl;
  for (int i(0); i <= t; i++) {
    string s = "";
    getline(cin, s);
    if (!s.empty()) {
      bool ans = possible_erase(s);
      if (ans)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
