#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long md = LLONG_MAX;
long long pow(long long val, long long pw) {
  if (pw == 0) return 1;
  if (pw % 2 == 0) {
    long long tmp = pow(val, pw / 2) % md;
    return (tmp * tmp) % md;
  } else
    return (val * pow(val, pw - 1)) % md;
}
void solve() {
  long long n, alp = 'a', ans = 1e6;
  string s;
  cin >> n >> s;
  for (long long i = 1; i <= 26; i++) {
    long long ta = 0, j = 0, k = n - 1, flg = 1;
    while (j <= k) {
      if (s[j] == s[k]) {
        j++;
        k--;
        continue;
      }
      if (s[j] == alp) {
        j++;
        ta++;
        continue;
      }
      if (s[k] == alp) {
        k--;
        ta++;
        continue;
      }
      flg = 0;
      break;
    }
    if (flg) ans = min(ans, ta);
    alp++;
  }
  if (ans != 1e6)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
int main() {
  init();
  long long t, cs = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
