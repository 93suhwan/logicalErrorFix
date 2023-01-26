#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (i % 2)
      a = a * 10 + s[i] - '0';
    else
      b = b * 10 + s[i] - '0';
  }
  cout << (a + 1) * (b + 1) - 2 << '\n';
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int TC;
  cin >> TC;
  while (TC--) {
    solve();
  }
  return 0;
}
