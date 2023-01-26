#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int countl = n;
    int countr = n;
    string s;
    string s1;
    for (int j = 0; j < n; j++) {
      s.push_back('(');
    }
    for (int j = n; j < 2 * n; j++) {
      s.push_back(')');
    }
    cout << s << "\n";
    for (int i = 1; i < n; i++) {
      for (int j = n - i; j < n + i; j++) {
        if (s[j] == '(') {
          s[j] = ')';
        } else {
          s[j] = '(';
        }
      }
      cout << s << "\n";
    }
  }
  return 0;
}
