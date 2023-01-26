#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, s1, s2;
    cin >> s;
    if (s.size() % 2 == 1)
      cout << "NO\n";
    else {
      s1 = s.substr(0, s.size() / 2);
      s2 = s.substr(s.size() / 2, s.size() / 2);
      if (s1 == s2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
