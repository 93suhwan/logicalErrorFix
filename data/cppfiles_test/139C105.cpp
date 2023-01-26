#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2 == 1) {
      cout << "NO"
           << "\n";
      continue;
    }
    if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size() / 2))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
