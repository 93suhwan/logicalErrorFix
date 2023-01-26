#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
void solve() {
  string str;
  int n;
  cin >> n;
  cin >> str;
  bool no = 1;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] != str[i - 1]) {
      cout << i << ' ' << i + 1 << endl;
      no = 0;
      break;
    }
  }
  if (no) cout << -1 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
