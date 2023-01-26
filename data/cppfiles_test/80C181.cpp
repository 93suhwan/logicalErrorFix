#include <bits/stdc++.h>
const long long INF = LLONG_MAX / 2;
const long long N = 2e5 + 1;
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l1 = -1, l2, r1, r2;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && l1 == -1) {
      l1 = i + 1;
      break;
    }
  }
  if (l1 == -1) {
    cout << 1 << " " << n / 2 << " " << 2 << " " << 1 + n / 2 << "\n";
    return;
  }
  if (l1 <= n / 2)
    cout << l1 << " " << n << " " << l1 + 1 << " " << n << "\n";
  else
    cout << 1 << " " << l1 << " " << 1 << " " << l1 - 1 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1, counti = 0;
  cin >> t;
  while (t--) {
    solve();
  }
}
