#include <bits/stdc++.h>
using namespace std;
bool check(string s, string t, int i, int j) {
  bool f1 = false, f2 = false, f3 = false;
  if (s[i + 1] == t[j]) f1 = check(s, t, i + 1, j + 1);
  if (!f1) {
    while (s[i - 1] == t[j] && i >= 1 && j < t.length()) {
      i--;
      j++;
    }
    if (j == t.length()) return true;
  }
  return f1;
}
int main() {
  int n, i, j, q, lcv;
  string s, t;
  long long ans;
  cin >> q;
  for (lcv = 0; lcv < q; lcv++) {
    cin >> s;
    cin.ignore(255, '\n');
    cin >> t;
    cin.ignore(255, '\n');
    for (i = 0; i < s.length(); i++) {
      if (s[i] == t[0]) {
        if (check(s, t, i, 1)) {
          cout << "YES\n";
          break;
        }
      }
    }
    if (i == s.length()) cout << "NO\n";
  }
  return 0;
}
