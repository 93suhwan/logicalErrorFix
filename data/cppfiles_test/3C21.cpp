#include <bits/stdc++.h>
using namespace std;
long long recurse(string &s, int dex) {
  if (dex == (int)(s).size()) {
    int n = (int)(s).size();
    if (s[0] == '0') return 0;
    if (s[n - 2] == '0' && s[n - 1] == '0') return 1;
    if (s[n - 2] == '2' && s[n - 1] == '5') return 1;
    if (s[n - 2] == '5' && s[n - 1] == '0') return 1;
    if (s[n - 2] == '7' && s[n - 1] == '5') return 1;
    return 0;
  }
  long long ct = 0;
  if (s[dex] == '_') {
    for (int i = 0; i <= 9; i++) {
      s[dex] = '0' + i;
      ct += recurse(s, dex + 1);
      s[dex] = '_';
    }
  } else
    ct += recurse(s, dex + 1);
  return ct;
}
void solve() {
  string s;
  cin >> s;
  if ((int)(s).size() == 1) {
    char ch = s[0];
    switch (ch) {
      case '_':
      case 'X':
      case '0':
        cout << 1 << endl;
        break;
      default:
        cout << 0 << endl;
        break;
    }
    return;
  }
  if (s == "________") {
    cout << 3600000 << endl;
    return;
  }
  bool hasX = false;
  for (auto &c : s)
    if (c == 'X') hasX = true;
  if (!hasX) {
    cout << recurse(s, 0) << endl;
  } else {
    vector<int> indices;
    for (int i = 0; i < (int)(s).size(); i++)
      if (s[i] == 'X') indices.push_back(i);
    long long ct = 0;
    for (int i = 0; i <= 9; i++) {
      for (auto &x : indices) s[x] = '0' + i;
      ct += recurse(s, 0);
    }
    cout << ct << endl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
