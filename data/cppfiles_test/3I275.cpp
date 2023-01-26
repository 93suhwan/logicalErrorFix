#include <bits/stdc++.h>
using namespace std;
long long ans;
bool x_first;
bool x_prelast;
bool x_last;
bool under_first;
bool under_prelast;
bool under_last;
bool x_null;
int x_mult = 10;
int u_mult = -1;
char f(string s) { return s[0]; }
char p(string s) { return s[s.size() - 2]; }
char l(string s) { return s[s.size() - 1]; }
bool x(char ch) { return ch == 'X'; }
bool u(char ch) { return ch == '_'; }
bool mask(char ch) { return x(ch) || u(ch); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  if (s == "0") {
    cout << 1 << endl;
    return 0;
  }
  if (s.size() == 1) {
    if (mask(f(s))) {
      cout << 1 << endl;
      return 0;
    }
    cout << 0 << endl;
    return 0;
  }
  if (x(f(s))) x_mult = 9;
  x_null = x(p(s)) && x(l(s));
  if (x_null) x_mult = 1;
  char ps = p(s);
  char ls = l(s);
  if (!mask(ps) && ps != '0' && ps != '2' && ps != '5' && ps != '7') {
    cout << 0 << endl;
    return 0;
  }
  if (ps == '0' && (!mask(ls) && ls != '0')) {
    cout << 0 << endl;
    return 0;
  }
  if (ps == '2' && (!mask(ls) && ls != '5')) {
    cout << 0 << endl;
    return 0;
  }
  if (ps == '5' && (!mask(ls) && ls != '0')) {
    cout << 0 << endl;
    return 0;
  }
  if (ps == '7' && (!mask(ls) && ls != '5')) {
    cout << 0 << endl;
    return 0;
  }
  if (!mask(ls) && ls != '0' && ls != '5') {
    cout << 0 << endl;
    return 0;
  }
  ans = 1;
  if (u(f(s)) && s.size() > 2) ans *= 9;
  bool was_x = x(f(s)) || x(ps) || x(ls);
  for (int i = 1; i < s.size() - 2; i++) {
    if (u(s[i])) ans *= 10;
    if (x(s[i])) was_x = true;
  }
  if (x(p(s)) || x(l(s))) {
    if (x(p(s)) && x(l(s))) {
      x_mult = x(f(s)) ? 0 : 1;
    } else if (x(p(s)) && !x(l(s))) {
      if (x(f(s))) {
        if (u(l(s)))
          x_mult = 3;
        else if (l(s) == '0')
          x_mult = 1;
        else
          x_mult = 2;
      } else {
        if (u(l(s)))
          x_mult = 4;
        else if (l(s) == '0')
          x_mult = 2;
        else
          x_mult = 2;
      }
    } else if (!x(p(s)) && x(l(s))) {
      if (s.size() > 2) {
        if (x(f(s))) {
          if (u(p(s)))
            x_mult = 3;
          else if (p(s) == '0')
            x_mult = 1;
          else
            x_mult = 2;
        } else {
          if (u(p(s)))
            x_mult = 4;
          else if (p(s) == '0')
            x_mult = 2;
          else
            x_mult = 2;
        }
      } else {
        if (u(p(s)))
          x_mult = 3;
        else
          x_mult = 1;
      }
    }
    u_mult = 1;
  } else {
    if (u(ps) || u(ls)) {
      if (s.size() > 2) {
        if (u(ps) && u(ls))
          u_mult = 4;
        else if (u(ps) && !u(ls))
          u_mult = 2;
        else
          u_mult = 1;
      } else {
        if (u(ps)) {
          if (u(ls))
            u_mult = 3;
          else if (ls == '5')
            u_mult = 2;
          else
            u_mult = 1;
        } else {
          u_mult = 1;
        }
      }
    } else {
      u_mult = 1;
    }
  }
  ans *= u_mult;
  if (was_x) ans *= x_mult;
  cout << ans << endl;
  return 0;
}
