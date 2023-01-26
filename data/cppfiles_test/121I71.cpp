#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int sa, sb, ss;
  sa = sb = ss = 0;
  if (a == b) return 0;
  for (int i = 0; i < n; i++) {
    sa += a[i] - '0';
    sb += b[i] - '0';
    if (a[i] != b[i]) ss++;
  }
  if (!sa || !sb) return -1;
  if (sa != sb && sa + sb != n + 1) return -1;
  ss = min(ss, n - ss);
  return ss;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
