#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long MAX = 3e5 + 10;
const long long Time = 86400;
const long long X = 131;
const long long inf = 0x3f3f3f3f;
const double PI = 1e-4;
double pai = 3.14159265358979323846;
long long T, n, m, k, x, ans;
string s;
long long a[MAX];
void solve() {
  long long j = 0;
  cin >> n >> k >> x;
  m = k;
  k = k + k * (k - 1) / 2;
  cin >> s;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '*') a[++j] = i;
  }
  long long i;
  for (i = 1; i <= j; i++)
    if (i * k >= x - 1) break;
  i = j - i + 1;
  if (i * k == x - 1) {
    for (long long ss = 0; ss < s.size(); ss++)
      if (s[ss] == 'a')
        cout << s[ss];
      else {
        for (long long t = i; t <= j; t++)
          if (ss == a[t])
            for (long long sss = 1; sss <= m; sss++) cout << "b";
      }
  } else {
    for (long long ss = 0; ss < s.size(); ss++)
      if (ss == a[i]) {
        for (long long t = x - 1 - (j - i) * k; t >= 1; t--) cout << "b";
      } else if (s[ss] == 'a')
        cout << s[ss];
      else {
        for (long long t = i + 1; t <= j; t++)
          if (ss == a[t])
            for (long long sss = 1; sss <= m; sss++) cout << "b";
      }
  }
  cout << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
