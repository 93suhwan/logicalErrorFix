#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (((s[0] == 'E') && (s[n - 1] == 'E')) ||
        ((s[0] == 'N') && (s[n - 1] == 'N')))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
