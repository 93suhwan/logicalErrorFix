#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  int f = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      f = 1;
      break;
    }
  }
  if (!f)
    cout << 0 << "\n";
  else {
    long long x = ceil(sqrt(n));
    int f1 = 0;
    for (int i = x; i <= n; i++) {
      if (s[i - 1] == c) {
        f1 = i;
        break;
      }
    }
    if (f1) {
      cout << 1 << "\n";
      cout << f1 << "\n";
    } else {
      cout << 2 << "\n";
      cout << n - 1 << " " << n << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
