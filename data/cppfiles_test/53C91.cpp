#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1ll) res = (res * x) % p;
    y = y >> 1ll;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  vector<int> v;
  int d = 0;
  for (auto a : s) {
    if (a != c) {
      d = 1;
      break;
    }
  }
  if (d == 0) {
    cout << 0 << "\n";
    return;
  }
  for (int i = n - 1; i >= n / 2; i--)
    if (s[i] == c) {
      cout << "1\n" << i + 1 << "\n";
      return;
    }
  cout << "2\n" << n - 1 << " " << n << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
