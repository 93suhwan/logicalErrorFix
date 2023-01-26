#include <bits/stdc++.h>
using namespace std;
using vll = vector<long long>;
long long mod = 1000000007;
long long modu(long long a, long long b) {
  long long c = a % b;
  return (c < 0) ? c + b : c;
}
long long ipow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b--) {
    ans = ans * a;
    ans %= m;
  }
  return ans;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  map<char, long long> mp;
  for (long long i = 0; i < n; i++) mp[s[i]]++;
  long long ans = 0, sing = 0;
  for (auto &x : mp) {
    if (x.second >= 2) {
      ans++;
    } else {
      sing++;
    }
  }
  cout << ans + sing / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
