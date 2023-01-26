#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve() {
  string s, t;
  cin >> s >> t;
  string p = s;
  sort(p.begin(), p.end());
  long long n = p.size();
  if (n < 3) {
    cout << p << endl;
    return;
  }
  map<char, int> mp;
  for (auto x : p) {
    mp[x]++;
  }
  char first;
  long long ib = 1001, ic = 1001;
  for (int i = 0; i < 3; i++) {
    if (t[i] == 'b')
      ib = i;
    else if (t[i] == 'c')
      ic = i;
  }
  if (mp['a'] == 0 || mp['b'] == 0 || mp['c'] == 0 || t[0] != 'a') {
    cout << p << endl;
    return;
  }
  if (ib < ic)
    first = 'b';
  else
    first = 'c';
  string ans = "";
  for (char c = 'a'; c <= 'z'; c++) {
    if (c == 'b' && first == 'b')
      ans += string(mp['c'], 'c');
    else if (c == 'c' && first == 'b')
      ans += string(mp['b'], 'b');
    else
      ans += string(mp[c], c);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
