#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int count = 0;
    cin >> s;
    int n = s.length();
    if (n % 2 != 0) {
      cout << "NO\n";
    } else {
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[i + (n / 2)]) count++;
      }
      if (count == n / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
