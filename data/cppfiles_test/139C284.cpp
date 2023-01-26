#include <bits/stdc++.h>
using namespace std;
bool is_square(string &str) {
  if (str.size() % 2 != 0) return false;
  int m = str.size() / 2;
  for (int i = 0; i < m; i++)
    if (str[i] != str[i + m]) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (is_square(s)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
