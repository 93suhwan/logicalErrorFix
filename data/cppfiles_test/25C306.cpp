#include <bits/stdc++.h>
using namespace std;
bool lefts(string s, string s1, long long i, long long j) {
  if (j == s1.length() - 1) {
    return true;
  } else {
    if (i > 0 && s[i - 1] == s1[j + 1]) {
      return lefts(s, s1, i - 1, j + 1);
    } else {
      return false;
    }
  }
}
bool helper(string s, string s1, long long i, long long j) {
  if (j == s1.length() - 1) {
    return true;
  } else {
    if (i < s.length() - 1 && s[i + 1] == s1[j + 1]) {
      return helper(s, s1, i + 1, j + 1);
    } else {
      if (i > 0 && s[i - 1] == s1[j + 1]) {
        return lefts(s, s1, i - 1, j + 1);
      } else {
        return false;
      }
    }
  }
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        bool ok = true;
        int ptr = 0;
        for (int k = i; k <= j; k++) {
          if (ptr == m || s[k] != t[ptr]) {
            ok = false;
            break;
          }
          ++ptr;
        }
        for (int k = j - 1; k >= 0; k--) {
          if (ptr == m) {
            break;
          }
          if (s[k] != t[ptr]) {
            ok = false;
            break;
          }
          ++ptr;
        }
        if (ok && ptr == m) {
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
}
