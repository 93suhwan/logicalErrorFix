#include <bits/stdc++.h>
using namespace std;
void solve() {
  int map[1000]{0};
  string s;
  cin >> s;
  int c1 = 0, c2 = 0;
  int ans = 0;
  int index;
  for (int i = 0; i < s.length(); i++) {
    index = s[i];
    map[index]++;
  }
  for (int i = 0; i < s.length(); i++) {
    index = s[i];
    if (map[index] >= 2) {
      map[index] = 0;
      c2++;
    } else if (map[index] == 1) {
      c1++;
    }
  }
  ans = (c1 / 2) + c2;
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
