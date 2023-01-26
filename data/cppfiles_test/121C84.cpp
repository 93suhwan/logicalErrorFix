#include <bits/stdc++.h>
using namespace std;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long int>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using vpll = vector<pair<long long int, long long int>>;
const long long int mod = 1e9 + 7, inf = 1e18;
long long int qpow(long long int x, long long int k) {
  long long int res = 1;
  while (k) {
    if (k & 1) res = res * x % mod;
    x = x * x % mod;
    k >>= 1;
  }
  return res;
}
long long int calc(string s, string t) {
  long long int count01 = 0, count10 = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1' && t[i] == '0') count10++;
    if (s[i] == '0' && t[i] == '1') count01++;
  }
  if (count01 == count10)
    return count01 + count10;
  else
    return INT_MAX;
}
long long int calc1(string s, string t, char c) {
  long long int ind = -1;
  for (long long int i = 0; i < s.length(); i++) {
    if (s[i] == '1' && t[i] == c) {
      ind = i;
      break;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    if (i == ind) continue;
    if (s[i] == '1')
      s[i] = '0';
    else
      s[i] = '1';
  }
  if (ind == -1) return INT_MAX;
  return calc(s, t);
}
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long int ans = calc(s, t);
  ans = min(ans, 1 + calc1(s, t, '1'));
  ans = min(ans, 1 + calc1(s, t, '0'));
  if (ans == INT_MAX)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
