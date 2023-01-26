#include <bits/stdc++.h>
using namespace std;
const bool read_file = false;
const char fi[] = "XX.inp";
const char fo[] = "XX.out";
void set_up() {
  if (read_file) {
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
  }
  cin.clear();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void just_do_it();
int main() {
  set_up();
  just_do_it();
}
bool ok(int x, string s) {
  deque<int> d;
  if (x == 0) {
    d.push_back(0);
  } else {
    while (x != 0) {
      d.push_front(x % 10);
      x /= 10;
    }
  }
  int f = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'X') {
      if (f == -1) {
        f = d[i];
      }
      if (f != d[i]) {
        return false;
      }
    } else if (s[i] != '_') {
      if (d[i] != s[i] - '0') {
        return false;
      }
    }
  }
  return true;
}
void just_do_it() {
  string s;
  cin >> s;
  int res = 0;
  int p;
  if (s.size() == 1) {
    if (ok(0, s)) {
      res++;
    }
  } else if (s.size() == 2) {
    if (ok(25, s)) {
      res++;
    }
    if (ok(50, s)) {
      res++;
    }
    if (ok(75, s)) {
      res++;
    }
  } else {
    p = 1;
    for (int i = 0; i < s.size() - 1; i++) {
      p *= 10;
    }
    for (int i = p; i < p * 10; i += 25) {
      if (ok(i, s)) {
        res++;
      }
    }
  }
  cout << res << endl;
}
