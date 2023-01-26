#include <bits/stdc++.h>
using namespace std;
int pos;
inline string done(int x, int y) {
  cout << x << y << endl;
  cout.flush();
  pos = y;
  string s;
  cin >> s;
  return s;
}
bool check(int x) {
  for (int i = (pos == 1 ? 2 : 1); i <= 8; i++) {
    string s = done(x, i);
    if (s == "Done") return true;
    if (s[0] == 68) return false;
    if (s[0] == 85) return check(x);
  }
  return false;
}
int main() {
  int T;
  while (T--) {
    pos = 1;
    for (int i = 1; i <= 8; i++) {
      if (done(i, pos) == "Done") break;
      if (check(i)) break;
    }
  }
  return 0;
}
