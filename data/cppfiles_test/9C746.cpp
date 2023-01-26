#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int fact(long long int n) {
  long long int res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i;
    res %= 1000000007;
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  int freq[26] = {};
  for (int i = 0; i < n; i++) freq[s[i] - 'a']++;
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > 1)
      ans++;
    else if (freq[i] == 1)
      cnt++;
  }
  ans += cnt / 2;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  cin >> tc;
  int z = 0;
  while (tc--) {
    solve();
  }
  return 0;
}
