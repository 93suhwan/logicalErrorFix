#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const long long maxn = 1e5 + 9;
long long a[maxn];
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long d = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'N') d++;
    }
    if (d == 0 || d > 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
