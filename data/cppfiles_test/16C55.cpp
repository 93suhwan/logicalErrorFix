#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int iINF = INT_MAX;
const long long INF = LLONG_MAX;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fpow(long long a, long long b, long long m) {
  if (!b) return 1;
  long long ans = fpow(a * a % m, b / 2, m);
  return (b % 2 ? ans * a % m : ans);
}
long long inv(long long a, long long m) { return fpow(a, m - 2, m); }
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int alp[26];
  for (long long i = 0; i < 26; i++) alp[i] = 0;
  for (long long i = 0; i < n; i++) {
    int k = s[i] - 'a';
    alp[k]++;
  }
  string a = "";
  for (long long i = 0; i < 26; i++) {
    for (long long j = 0; j < alp[i]; j++) a += (i + 'a');
  }
  int cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != a[i]) cnt++;
  }
  cout << cnt << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
