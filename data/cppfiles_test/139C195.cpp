#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (s.substr(0, n / 2) == s.substr(n / 2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
