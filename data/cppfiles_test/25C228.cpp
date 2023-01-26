#include <bits/stdc++.h>
using namespace std;
int izq(string s, string t, int i, int j) {
  while (j < t.length() && i >= 0) {
    if (t[j] == s[i]) {
      j++;
      i--;
    } else {
      break;
    }
  }
  if (j == t.length()) {
    return 1;
  }
  return 0;
}
int der(string s, string t, int i, int j) {
  if (j == t.length()) {
    return 1;
  }
  if (j + 1 == t.length()) {
    if (i + 1 < s.length() && s[i + 1] == t[j]) {
      return 1;
    } else if (i - 1 >= 0 && s[i - 1] == t[j]) {
      return 1;
    } else {
      return 0;
    }
  }
  int r1 = 0, r2 = 0;
  if (i - 1 >= 0 && s[i - 1] == t[j]) {
    r1 = izq(s, t, i - 1, j);
  }
  if (r1) {
    return 1;
  }
  if (i + 1 < s.length() && s[i + 1] == t[j]) {
    r2 = der(s, t, i + 1, j + 1);
  }
  return (r1 || r2);
}
int main() {
  int casos;
  cin >> casos;
  for (int lim = 0; lim < casos; lim++) {
    string s, t;
    cin >> s >> t;
    int f = 0;
    int l = t.length();
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == t[0]) {
        f = der(s, t, i, 1);
        if (f == 1) {
          break;
        }
      }
    }
    if (f) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
