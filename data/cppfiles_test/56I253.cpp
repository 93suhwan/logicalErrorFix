#include <bits/stdc++.h>
using namespace std;
vector<string> iz;
int64_t vkr(int64_t iv) {
  int64_t ans = iv;
  for (auto c : iz) {
    if (c[0] == 'U')
      ans--;
    else if (c[0] == 'D')
      ans++;
  }
  return ans;
}
bool query(int64_t x, int64_t y, int64_t &posk) {
  cout << x << ' ' << y << endl;
  string kp;
  cin >> kp;
  if (kp == "Done") return true;
  if (kp[0] == 'U')
    posk--;
  else if (kp[0] == 'D')
    posk++;
  iz.push_back(kp);
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    iz.clear();
    for (int i = 2; i <= 8; ++i) {
      int64_t x = 1, y = 1;
      int64_t posk = vkr(i);
      if (query(x, y, posk)) break;
      int yes = 0;
      while (x != 7 || y != 7) {
        if (posk - x >= 2) {
          x = posk - 1;
          if (query(x, y, posk)) {
            yes = 1;
            break;
          }
        } else {
          if (y == 7) {
            x = 7;
            query(x, y, posk);
            break;
          }
          y++;
          if (query(x, y, posk)) {
            yes = 1;
            break;
          }
        }
      }
      if (yes) break;
    }
  }
}
