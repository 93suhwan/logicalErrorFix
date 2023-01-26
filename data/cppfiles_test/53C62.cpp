#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  int bad = n - count(s.begin(), s.end(), c);
  if (!bad) {
    cout << "0\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    bool ok = 1;
    for (int j = i; j <= n; j += i) ok &= (s[j - 1] == c);
    if (ok) {
      cout << 1 << "\n" << i << "\n";
      return;
    }
  }
  cout << "2\n" << n - 1 << " " << n << "\n";
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
