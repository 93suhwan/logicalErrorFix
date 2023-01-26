#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2 != 0)
      cout << "NO" << endl;
    else {
      string a = s.substr(0, s.size() / 2);
      string b = s.substr(s.size() / 2, s.size());
      if (a == b)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
