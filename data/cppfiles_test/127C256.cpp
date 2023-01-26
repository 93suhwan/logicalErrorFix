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
  sort(s.begin(), s.end());
  unordered_map<char, long long> cnt;
  long long n = s.size();
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  if (t != "abc" || cnt['a'] == 0 || cnt['b'] == 0 || cnt['c'] == 0) {
    cout << s << endl;
    return;
  }
  string ans = "";
  ans += string(cnt['a'], 'a');
  ans += string(cnt['c'], 'c');
  ans += string(cnt['b'], 'b');
  for (char c = 'd'; c <= 'z'; c++) {
    ans += string(cnt[c], c);
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
