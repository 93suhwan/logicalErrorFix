#include <bits/stdc++.h>
using namespace std;
string checker(string &s, string &t, long long idx1, long long idx2) {
  if (idx2 == t.size()) {
    return "yes";
  }
  string ans = "no";
  if ((idx1 + 1) < s.size() && s[idx1 + 1] == t[idx2]) {
    ans = checker(s, t, idx1 + 1, idx2 + 1);
    if (ans == "yes") {
      return ans;
    }
  }
  if (idx1 - 1 >= 0 && s[idx1 - 1] == t[idx2]) {
    ans = checker(s, t, idx1 - 1, idx2 + 1);
    if (ans == "yes") {
      return ans;
    }
  }
  return ans;
}
string solve() {
  string s, t;
  cin >> s >> t;
  string ans = "no";
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == t[0]) {
      ans = checker(s, t, i, 1);
      if (ans == "yes") {
        return ans;
      }
    }
  }
  return "no";
}
int main() {
  long long test;
  cin >> test;
  while (test--) {
    cout << solve() << '\n';
  }
}
