#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c x, c y) {
  return rge<c>{x, y};
}
template <class c>
auto ptb(c* x) -> decltype(cerr << *x, 0);
template <class c>
char ptb(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
string s;
bool check(int n) {
  string nw;
  while (n) nw += '0' + (n % 10), n /= 10;
  reverse(nw.begin(), nw.end());
  if (s.size() != nw.size()) return 0;
  char x = '?';
  for (int i = 0; i < (int)(s.size()); i++) {
    if (s[i] == 'X') {
      if (x == '?')
        x = nw[i];
      else if (x != nw[i])
        return false;
    } else if (s[i] != '_' && s[i] != nw[i])
      return false;
  }
  return true;
}
void solve() {
  cin >> s;
  if (s.size() == 1) {
    cout << (s == "0" || s == "X" || s == "_") << '\n';
    return;
  }
  int ans = 0;
  int st = 1;
  for (int i = 0; i < (int)(s.size()); i++) st *= 10;
  st /= 25, st *= 25;
  for (int i = (st / 10 / 25 * 25); i <= (int)(st - 1); i += (25)) {
    if (check(i)) ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
