#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rrrrrrrrrrrrbbbbbbbbbbbbbbb,
      ccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbb, rrrrrrrrrddddddddd,
      cccccccdddddddddddd;
  cin >> n >> m >> rrrrrrrrrrrrbbbbbbbbbbbbbbb >>
      ccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbb >> rrrrrrrrrddddddddd >>
      cccccccdddddddddddd;
  int cccccccccccccoooooooooooouuuuuuuuuuunnnnnnnnnnntttttttttttt = 0;
  int d1111111111111111 = 1;
  int d2222222222222222222222222222 = 1;
  while (1) {
    if (rrrrrrrrrrrrbbbbbbbbbbbbbbb == rrrrrrrrrddddddddd or
        ccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbb == cccccccdddddddddddd) {
      cout << cccccccccccccoooooooooooouuuuuuuuuuunnnnnnnnnnntttttttttttt
           << "\n";
      return;
    }
    if (rrrrrrrrrrrrbbbbbbbbbbbbbbb == (n)) {
      if (d1111111111111111 > 0) d1111111111111111 = -d1111111111111111;
    } else if (rrrrrrrrrrrrbbbbbbbbbbbbbbb == 0) {
      if (d1111111111111111 < 0) d1111111111111111 = -d1111111111111111;
    }
    if (ccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbb == m) {
      if (d2222222222222222222222222222 > 0)
        d2222222222222222222222222222 = -d2222222222222222222222222222;
    } else if (ccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbb == 0) {
      if (d2222222222222222222222222222 < 0)
        d2222222222222222222222222222 = -d2222222222222222222222222222;
    }
    rrrrrrrrrrrrbbbbbbbbbbbbbbb += d1111111111111111;
    ccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbb += d2222222222222222222222222222;
    cccccccccccccoooooooooooouuuuuuuuuuunnnnnnnnnnntttttttttttt++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
