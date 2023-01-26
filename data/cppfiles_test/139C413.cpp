#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s[t];
  string temp;
  for (int i = 0; i < t; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < t; i++) {
    temp = s[i];
    if (s[i].length() % 2 != 0) {
      cout << "NO\n";
      continue;
    }
    int n = s[i].length();
    s[i].erase(n / 2);
    s[i] = s[i] + s[i];
    if (temp.compare(s[i]) == 0) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
