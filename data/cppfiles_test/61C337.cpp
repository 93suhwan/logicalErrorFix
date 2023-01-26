#include <bits/stdc++.h>
int count_dis(std::string& s) {
  int ans = 0;
  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == s[i + 1]) ++ans;
  }
  return ans;
}
std::string answ(std::string& s, int n, char last) {
  std::string ans;
  int ptr = 0;
  while (ptr < n) {
    while (ptr < n && s[ptr] == '?') {
      if (last == 'R') {
        ans += "B";
        last = 'B';
      } else {
        ans += "R";
        last = 'R';
      }
      ++ptr;
    }
    if (ptr < n) {
      ans += s[ptr];
      last = s[ptr];
      ++ptr;
    }
  }
  return ans;
}
void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  char last = '?';
  if (s[0] == '?') {
    std::string a1 = answ(s, n, 'R');
    std::string a2 = answ(s, n, 'B');
    if (count_dis(a1) < count_dis(a2)) {
      std::cout << a1 << '\n';
      return;
    } else {
      std::cout << a2 << '\n';
      return;
    }
  } else {
    std::cout << answ(s, n, s[0]) << '\n';
  }
}
int main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}
