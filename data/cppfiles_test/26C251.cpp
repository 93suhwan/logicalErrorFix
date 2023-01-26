#include <bits/stdc++.h>
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz";
int res(string st) {
  int ans = 0, ga = 0, gb = 0, ra = 5, rb = 5;
  for (int i = 0; i < 10; i++) {
    if ((ga + ra < gb) || (gb + rb < ga)) break;
    if (i % 2 == 0) {
      ra--;
      if (st[i] == '1') ga++;
    } else {
      rb--;
      if (st[i] == '1') gb++;
    }
    ans++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1, tt = 0;
  cin >> t;
  while (t--) {
    string st, a, b;
    cin >> st;
    for (int i = 0; i < 10; i++) {
      if (st[i] == '?') {
        if (i % 2 == 0) {
          a.push_back('1');
        } else {
          a.push_back('0');
        }
      } else {
        a.push_back(st[i]);
      }
    }
    for (int i = 0; i < 10; i++) {
      if (st[i] == '?') {
        if (i % 2) {
          b.push_back('1');
        } else {
          b.push_back('0');
        }
      } else {
        b.push_back(st[i]);
      }
    }
    cout << min(res(a), res(b)) << endl;
  }
  return 0;
}
