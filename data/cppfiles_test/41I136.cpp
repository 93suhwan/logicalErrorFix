#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f;
using namespace std;
void sol() {
  long long n, m;
  while (cin >> n >> m) {
    string s;
    cin.ignore();
    cin >> s;
    long long x[n];
    memset(x, 0, sizeof(x));
    ;
    for (long long i = 1; i < s.size(); i++) {
      x[i] = x[i - 1];
      if (s[i] == s[i - 1]) x[i]++;
    }
    while (m--) {
      long long a, b;
      cin >> a >> b;
      long long ans = x[b - 1] - x[a - 1];
      if (ans) ans += (b - a) / 3;
      cout << ans << "\n";
    }
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    sol();
    cout.flush();
  }
  return 0;
}
