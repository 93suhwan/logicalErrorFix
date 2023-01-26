#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2 == 0 && s.size() != 4)
      cout << "Yes\n";
    else if (s.size() == 4 && s[0] == s[2] && s[1] == s[3])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
