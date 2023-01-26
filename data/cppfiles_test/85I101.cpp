#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
void solve() {
  string s;
  cin >> s;
  int p1 = 0, p2 = s.size() - 1;
  int st = p1, en = p2;
  bool l = false, r = false;
  bool z = false, o = false;
  while (p1 <= p2) {
    if ((s[p1] == '0' || s[p2] == '0') && (l && r)) {
      z = true;
    }
    if ((s[p2] == '1' || s[p1] == '1') && (l && r)) {
      o = true;
    }
    if (s[st] == s[p1 + 1] && !l) {
      st++;
    } else
      l = true;
    if (s[en] == s[p2 - 1] && !r) {
      en--;
    } else
      r = true;
    p1++;
    p2--;
  }
  if (en < st) {
    if (s[en] - 48)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  } else {
    if (z && o) {
      cout << 2 << endl;
    } else if (z && !o) {
      int x, y;
      if (s[st] - 48)
        x = 0;
      else
        x = 1;
      if (s[en] - 48)
        y = 0;
      else
        y = 1;
      cout << x + y + 1 << endl;
    } else if (!z && o) {
      int x, y;
      if (s[st] - 48)
        x = 0;
      else
        x = 1;
      if (s[en] - 48)
        y = 0;
      else
        y = 1;
      cout << x + y << endl;
    } else {
      int x, y;
      if (s[st] - 48)
        x = 0;
      else
        x = 1;
      if (s[en] - 48)
        y = 0;
      else
        y = 1;
      cout << x + y << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
