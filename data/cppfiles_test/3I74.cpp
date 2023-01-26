#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
bool check(char a, char b) { return a == 'X' || a == '_' || a == b; }
bool check(string &s, string &tail) {
  char a1 = s[s.size() - 2];
  char a2 = s[s.size() - 1];
  if (a1 == a2 && a1 == 'X' && tail[0] != tail[1]) return false;
  return check(a1, tail[0]) && check(a2, tail[1]);
}
bool update(string &s, string tail) {
  long long t1 = s.size() - 2, t2 = s.size() - 1;
  if (s[t1] == 'X' || s[t2] == 'X') {
    long long i = s[t2] == 'X' ? t2 : t1;
    char ch = s[t2] == 'X' ? tail[1] : tail[0];
    while (i >= 0 && s[i] == 'X') {
      s[i] = ch;
      i--;
    }
  }
  if (s[t1] == '_') {
    s[t1] = tail[0];
  }
  if (s[t2] == '_') {
    s[t2] = tail[1];
  }
  return s[0] != '0' && check(s[t1], tail[0]) && check(s[t2], tail[1]);
}
long long foo(string s, string tail) {
  if (update(s, tail) == false) return 0;
  long long res = 1;
  for (long long i = 0; i < s.size();) {
    if (s[i] != '_' && s[i] != 'X') {
      i++;
      continue;
    }
    res *= i > 0 ? 10 : 9;
    if (s[i] == 'X') {
      while (i < s.size() && s[i] == 'X') {
        i++;
      }
    } else {
      i++;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  long long res;
  if (s.size() == 1) {
    res = (long long)(s[0] == '_' || s[0] == 'X' || s[0] == '0');
  } else {
    res = foo(s, "25") + foo(s, "50") + foo(s, "00");
  }
  cout << res;
}
