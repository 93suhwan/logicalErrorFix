#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 0x3f3f3f3f;
const long long modn = 1e9;
const long long N = 1e5 + 5;
void solve() {
  long long n;
  cin >> n;
  getchar();
  string s;
  cin >> s;
  long long idx = -1;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    if (n % 2 == 0)
      cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n << '\n';
    else
      cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n - 1 << '\n';
  } else {
    idx++;
    if (idx <= n / 2) {
      cout << idx << " " << n << " " << idx + 1 << " " << n << '\n';
    } else {
      cout << 1 << " " << idx << " " << 1 << " " << idx - 1 << '\n';
    }
  }
}
signed main() {
  long long _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
