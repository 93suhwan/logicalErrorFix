#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long N = 3e5 + 100, M = 6e5 + 100, Q = 5e5 + 100, K = 20, INF = 1e18,
                MOD = 1e9 + 7;
long long t, x, y;
string e;
void go(long long q, long long w) {
  if (q == x && w == y) return;
  x = q;
  y = w;
  cout << q << " " << w << endl;
  string s;
  cin >> s;
  e = s;
}
void solve() {
  cin >> t;
  while (t-- > 0) {
    x = 1, y = 1;
    go(x, y);
    if (e == "Done") {
      continue;
    }
    long long dir = 1;
    bool fl = false;
    while (e != "Done") {
      if (e == "Down" || e == "Down-Right" || e == "Down-Left") {
        go(x + 1, y);
        if (e == "Done") break;
        go(x, 1);
        dir = 1;
        fl = false;
        continue;
      }
      if (e == "Up" || e == "Up-Left" || e == "Up-Right") {
        go(x, 1);
        dir = 1;
        fl = true;
        continue;
      }
      if (dir == 1) {
        if (y == 8) {
          if (fl) {
            fl = false;
            go(x, y - 1);
          } else {
            go(x + 1, y);
          }
          dir = 0;
        } else {
          go(x, y + 1);
        }
      } else {
        if (y == 1) {
          if (fl) {
            fl = false;
            go(x, y + 1);
          } else {
            go(x + 1, y);
          }
          dir = 1;
        } else {
          go(x, y - 1);
        }
      }
    }
  }
  cout << endl;
}
