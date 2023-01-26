#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (s == "EN" || s == "NEE" || s == "ENE" || s == "EEN")
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
