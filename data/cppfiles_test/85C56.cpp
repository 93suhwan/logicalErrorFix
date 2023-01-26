#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x7fffffff;
void solve() {
  string s;
  cin >> s;
  int tong = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s[i + 1]) {
      if (s[i] == '0') tong += 1;
    }
  }
  cout << min(tong, 2) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
