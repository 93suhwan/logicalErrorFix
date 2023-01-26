#include <bits/stdc++.h>
using namespace std;
long long const N = 3e4 + 3, oo = 1e7;
void solve() {
  string a, b, s;
  cin >> a >> s;
  while (!a.empty()) {
    if (s.empty()) {
      cout << "-1\n";
      return;
    }
    int x = s.back() - '0';
    s.pop_back();
    if (x < a.back() - '0') {
      if (s.empty()) {
        cout << "-1\n";
        return;
      }
      x += (s.back() - '0') * 10;
      s.pop_back();
    }
    int ch = (x - a.back() + '0');
    if (ch > 9) {
      cout << "-1\n";
      return;
    }
    b.push_back(char('0' + ch));
    a.pop_back();
  }
  reverse(b.begin(), b.end());
  s += b;
  reverse(s.begin(), s.end());
  while (s.back() == '0') s.pop_back();
  reverse(s.begin(), s.end());
  cout << s << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
