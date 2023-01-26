#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mod = 998244353;
void solve() {
  int n, m;
  cin >> n >> m;
  int x = 1, y = 1;
  string s1;
  cin >> s1;
  vector<char> vec1, vec2;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == 'R' || s1[i] == 'L') {
      vec1.push_back(s1[i]);
    } else {
      vec2.push_back(s1[i]);
    }
  }
  int temp = 0;
  int zuo = 0;
  int you = 0;
  for (auto v : vec1) {
    if (v == 'L') temp--;
    if (v == 'R') temp++;
    zuo = max(zuo, -temp);
    you = max(you, temp);
    if (zuo + you + 1 <= m) {
      x = zuo + 1;
    }
  }
  temp = 0;
  int shang = 0, xia = 0;
  for (auto v : vec2) {
    if (v == 'U') temp++;
    if (v == 'D') temp--;
    shang = max(shang, temp);
    xia = max(xia, -temp);
    if (shang + xia + 1 <= n) {
      y = shang + 1;
    }
  }
  cout << y << ' ' << x << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
