#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void pr(Args... args) {}
using ll = long long;
const char nl = '\n';
const int MX = 2e5 + 10;
bool sub(string s, string t) {
  int m = ((int)(t.size())), i = 0;
  for (char ch : s) {
    if (ch == t[i]) {
      i++;
    }
  }
  return i == m;
}
void solve() {
  string s, t;
  cin >> s >> t;
  if (t != "abc") {
    sort(s.begin(), s.end());
    cout << s << nl;
    return;
  }
  sort(s.begin(), s.end());
  if (s[0] != 'a') {
    cout << s << nl;
    return;
  }
  int cnt[200] = {0};
  for (char ch : s) ++cnt[(int)ch];
  for (int rep = 0; rep < cnt['a']; rep++) cout << 'a';
  for (int rep = 0; rep < cnt['c']; rep++) cout << 'c';
  for (int rep = 0; rep < cnt['b']; rep++) cout << 'b';
  for (char ch = 'd'; ch <= 'z'; ch++)
    for (int rep = 0; rep < cnt[ch]; rep++) cout << ch;
  cout << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  cin >> te;
  while (te--) {
    solve();
  }
}
