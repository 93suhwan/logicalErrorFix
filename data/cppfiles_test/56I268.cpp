#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5) + 12, mod = int(1e9) + 7;
int cnt[20];
void solve() {
  int x = 1, y = 1, ok = 1, first = 0;
  memset(cnt, 0, sizeof(cnt));
  while (true) {
    cout << x << " " << y << endl;
    string second;
    cin >> second;
    cnt[x]++;
    if (second == "Done") return;
    if (second == "Down" || second == "Down-Right" || second == "Down-Left" ||
        ((y == 1 || y == 8) && cnt[x] >= 8)) {
      x++;
    } else {
      if (ok) {
        if (y == 8) {
          y--;
          ok = 0;
        } else
          y++;
      } else {
        if (y == 1) {
          y++;
          ok = 1;
        } else
          y--;
      }
    }
  }
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
