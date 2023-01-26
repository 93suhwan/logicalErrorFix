#include <bits/stdc++.h>
using namespace std;
int powmod(int x, int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % p;
    y /= 2;
    x = (x * x) % p;
  }
  return res;
}
string dectobin(int x) {
  string s = "";
  while (x > 0) {
    int t = x % 2;
    s.push_back(t + '0');
    x /= 2;
  }
  reverse(s.begin(), s.end());
  if (s.compare("") == 0)
    return "0";
  else
    return s;
}
int long long bintodec(string s) {
  int long long ans = 0;
  int long long n = s.size();
  for (int long long i = n - 1; i >= 0; i--) {
    if (s[i] == '1') ans += pow(2, n - i - 1);
  }
  return ans;
}
int find(int k, int n) { return ((n & (1 << (k - 1))) >> (k - 1)); }
int long long f[100000 + 1];
int32_t main() {
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    f[i] = ((i << 1) - 1ll) * f[i - 1] % 1000000007 * (i << 1) % 1000000007;
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int long long n;
    cin >> n;
    cout << f[n] << "\n";
  }
}
