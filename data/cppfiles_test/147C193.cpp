#include <bits/stdc++.h>
using namespace std;
bool check(string s, int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') {
      cnt++;
    }
  }
  if (cnt == 1) {
    return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (check(s, n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
