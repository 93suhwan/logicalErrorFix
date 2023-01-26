#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() > 3) {
      cout << "YES\n";
      continue;
    }
    if (s.size() == 2) {
      if (s == "EE" or s == "NN")
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      int e = 0;
      for (auto x : s)
        if (x == 'E') e++;
      if (e == 2)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
