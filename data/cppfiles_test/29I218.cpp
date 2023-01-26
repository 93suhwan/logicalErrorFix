#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
int const M = 2e5 + 10;
long long n, m, x, y, s[M], t, a, b, c;
map<long long, long long> cnt;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cnt.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      ++cnt[s[i]];
    }
    cout << cnt[1] * (1 << cnt[0]) << "\n";
  }
  return 0;
}
