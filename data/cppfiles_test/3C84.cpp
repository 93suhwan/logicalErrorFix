#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &a, U b) {
  a = (a > b ? b : a);
}
template <typename T, typename U>
inline void amax(T &a, U b) {
  a = (a > b ? a : b);
}
int pw[9], ans;
void solve(int i, string &s, int num = 0, int x = 0) {
  do {
  } while (0);
  if (i == ((int)s.size())) {
    do {
    } while (0);
    ans += (num % 25 == 0);
    return;
  }
  if (i > 0 && !num) return;
  if (s[i] >= '0' && s[i] <= '9') {
    num += (s[i] - '0') * pw[((int)s.size()) - i - 1];
    solve(i + 1, s, num, x);
  } else {
    if (s[i] == 'X') {
      if (x)
        solve(i + 1, s, num, x);
      else {
        for (int d = 0; d <= 9; ++d) {
          int here = num;
          for (int j = i; j < ((int)s.size()); ++j) {
            if (s[j] == 'X') here += d * pw[((int)s.size()) - j - 1];
          }
          solve(i + 1, s, here, 1);
        }
      }
    } else {
      for (int d = 0; d <= 9; ++d) {
        solve(i + 1, s, num + d * pw[((int)s.size()) - i - 1], x);
      }
    }
  }
}
void solve() {
  pw[0] = 1;
  for (int i = 1; i < 9; ++i) pw[i] = pw[i - 1] * 10;
  string s;
  cin >> s;
  solve(0, s, 0);
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests = 1;
  while (tests--) {
    solve();
  }
}
