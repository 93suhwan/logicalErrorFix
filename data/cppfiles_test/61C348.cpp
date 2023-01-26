#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using vi = vector<ll>;
using pii = pair<ll, ll>;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll k = 0;
  while (s[k] == '?' && k < n) k++;
  for (ll i = k + 1; i < n; i++) {
    if (s[i] != '?')
      continue;
    else if (s[i - 1] == 'R')
      s[i] = 'B';
    else if (s[i - 1] == 'B')
      s[i] = 'R';
  }
  for (ll i = k - 1; i >= 0; i--) {
    if (s[i] != '?')
      continue;
    else if (s[i + 1] == 'R')
      s[i] = 'B';
    else if (s[i + 1] == 'B')
      s[i] = 'R';
    else if (s[i + 1] == '\0')
      s[i] = 'B';
  }
  cout << s << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--) solve();
}
