#include <bits/stdc++.h>
using namespace std;
bool endgame(int i, int c1, int c2) { return 5 - i / 2 + c2 < c1; }
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
  for (int i = 0; i < (int)(10); i++) cout << v1[i];
  cout << '\n';
  for (int i = 0; i < (int)(10); i++) cout << v2[i];
  cout << '\n';
  int c1 = 0, c2 = 0;
  int res1 = 10, res2 = 10;
  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 1 && v1[i - 1] == 1)
      c1++;
    else if (i % 2 == 0 && v1[i - 1] == 1)
      c2++;
    if (endgame(i, c1, c2)) {
      res1 = i;
      break;
    }
  }
  c1 = 0;
  c2 = 0;
  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0 && v2[i - 1] == 1)
      c1++;
    else if (i % 2 == 1 && v2[i - 1] == 1)
      c2++;
    if (5 - (i + 1) / 2 + c2 < c1) {
      res2 = i;
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
