#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 2 && s[0] != s[1])
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
