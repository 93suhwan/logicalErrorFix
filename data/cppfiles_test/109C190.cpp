#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, true : false;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return b > a ? a = b, true : false;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i < (n); i++) {
    if (s[i] != '0') {
      if (i != n - 1) {
        res++;
      }
      res += (s[i] - '0');
    }
  }
  cout << res << '\n';
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
