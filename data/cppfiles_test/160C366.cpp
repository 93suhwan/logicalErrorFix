#include <bits/stdc++.h>
using namespace std;
bool check(int a1, int a2, int c1, int c2) {
  if (c1 == a1) return true;
  if (c2 == a2) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, r, c, rr, cc;
    cin >> n >> m >> r >> c >> rr >> cc;
    int tim = 0, dc = 1, dr = 1;
    while (!check(rr, cc, r, c)) {
      r += dr;
      c += dc;
      if (r > n) {
        dr = -1;
        r += dr - 1;
      }
      if (c > m) {
        dc = -1;
        c += dc - 1;
      }
      ++tim;
    }
    cout << tim << '\n';
  }
  return 0;
}
