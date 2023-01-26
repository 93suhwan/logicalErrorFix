#include <bits/stdc++.h>
using namespace std;
long long sigma(long long l, long long r) {
  return ((r * (r + 1)) / 2) - ((l * (l - 1)) / 2);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
long long dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string x;
    cin >> x;
    long long n = x.size() / 2;
    if (x.size() % 2)
      cout << "NO" << '\n';
    else {
      string s = x.substr(0, n);
      string d = x.substr(n, n);
      cout << (s == d ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}
