#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s == "EN" || s == "NE") {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
  return 0;
}
