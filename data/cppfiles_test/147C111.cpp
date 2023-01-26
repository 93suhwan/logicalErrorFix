#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'E') {
      } else {
        b++;
      }
    }
    if (b != 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
