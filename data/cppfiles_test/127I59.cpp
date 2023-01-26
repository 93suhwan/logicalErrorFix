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
  string other;
  {
    string S;
    for (char ch : s) {
      if (ch == 'a' || ch == 'b' || ch == 'c') {
        S += ch;
      } else {
        other += ch;
      }
    }
    sort(other.begin(), other.end());
    s = S;
  }
  string order = "abc";
  string ans = s;
  do {
    sort(s.begin(), s.end(), [&](char x, char y) {
      return find(order.begin(), order.end(), x) - order.begin() <
             find(order.begin(), order.end(), y) - order.begin();
    });
    if (!sub(s, t)) ans = min(ans, s);
  } while (next_permutation(order.begin(), order.end()));
  cout << ans + other << nl;
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
