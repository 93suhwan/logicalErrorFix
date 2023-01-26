#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'E')
        x++;
      else
        continue;
    }
    if (x == s.length() - 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
