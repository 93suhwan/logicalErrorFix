#include <bits/stdc++.h>
using namespace std;
void solve() {
  int map[100000]{0};
  string s;
  cin >> s;
  int rc;
  int ans = 0;
  rc = s.length() / 2;
  int index;
  for (int i = 0; i < s.length(); i++) {
    index = s[i];
    map[index]++;
  }
  for (int i = 0; i < s.length(); i++) {
    index = s[i];
    if (map[index] >= 2 && rc != 0) {
      ans++;
      rc--;
      map[index] = 0;
    }
    if (map[index] == 1 && rc != 0) {
      ans++;
      rc--;
    }
  }
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
