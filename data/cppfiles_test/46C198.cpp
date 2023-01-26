#include <bits/stdc++.h>
using namespace std;
int n;
long long c[666666];
void fakemain() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  long long ans = 0;
  for (int i = 2; i <= n; i += 2) {
    long long cs = 0, mi = -1;
    for (int j = i; j <= n; ++j) {
      long long L = max(-mi, 1 - cs), R = min(c[i - 1], c[j] - cs);
      if (L <= R && (j - i + 1) % 2 == 1) ans += R - L + 1;
      if ((j - i + 1) & 1)
        cs -= c[j];
      else
        cs += c[j];
      mi = min(mi, cs);
    }
  }
  cout << ans << "\n";
}
int main() { fakemain(); }
