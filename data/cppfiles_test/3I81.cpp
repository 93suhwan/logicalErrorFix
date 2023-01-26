#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
bool check(char a, char b) { return a == '_' || a == b; }
long long foo(string s, string tail) {
  if (!check(s[s.size() - 2], tail[0]) || !check(s.back(), tail[1])) return 0;
  s[s.size() - 2] = tail[0];
  s[s.size() - 1] = tail[1];
  if (s[0] == '0') return 0;
  long long res = 1;
  for (long long i = 0; i + 2 < s.size(); i++) {
    if (s[i] == '_') {
      res *= i > 0 ? 10 : 9;
    }
  }
  return res;
}
string x(string s, long long val) {
  for (auto &i : s) {
    if (i == 'X') {
      i = '0' + val;
    }
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  long long res = 0;
  if (s.size() == 1) {
    res = (long long)(s[0] == '_' || s[0] == 'X' || s[0] == '0');
  } else {
    if (count(s.begin(), s.end(), 'X')) {
      for (long long i = 0; i < 10; i++) {
        string temp = x(s, i);
        res += foo(temp, "25") + foo(temp, "50") + foo(temp, "00");
      }
    } else {
      res += foo(s, "25") + foo(s, "50") + foo(s, "00");
    }
  }
  cout << res;
}
