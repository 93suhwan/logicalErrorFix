#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<bool> v1, v2;
  string s;
  cin >> s;
  for (int i = 1; i <= 10; i++) {
    if (s[i - 1] == '?') {
      v1.push_back(i % 2);
      v2.push_back((i + 1) % 2);
    } else {
      bool t = s[i - 1] - '0';
      v1.push_back(t);
      v2.push_back(t);
    }
  }
  int c1 = 0, c2 = 0;
  int res1 = 10, res2 = 10;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0 && v1[i] == 1)
      c1++;
    else if (i % 2 == 1 && v1[i] == 1)
      c2++;
    if (c1 > c2 + 5 - i / 2) {
      res1 = i + 1;
      break;
    }
  }
  c1 = 0;
  c2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0 && v2[i] == 1)
      c1++;
    else if (i % 2 == 1 && v2[i] == 1)
      c2++;
    if (c2 > c1 + 4 - i / 2) {
      res2 = i + 1;
      break;
    }
  }
  cout << min(res1, res2) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
