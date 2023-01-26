#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int m = 0;
    for (int i = 0; s[i]; i++) {
      if (s[i] == 'N') m++;
    }
    if (m == 1) {
      cout << "NO";
    } else
      cout << "YES";
    cout << "\n";
  }
  return 0;
}
