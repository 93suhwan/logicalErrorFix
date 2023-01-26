#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long binpow(long long a, long long b, long long mod) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, s;
    cin >> a >> s;
    vector<long long> b;
    int f = 1;
    while (s) {
      int x = a % 10;
      int y = s % 10;
      if (x <= y)
        b.push_back(y - x);
      else {
        s /= 10;
        y += 10 * (s % 10);
        if (x < y && y >= 10 && y <= 18)
          b.push_back(y - x);
        else {
          f = 0;
          break;
        }
      }
      s /= 10;
      a /= 10;
    }
    if (a) f = 0;
    if (!f)
      cout << -1 << endl;
    else {
      while (b.back() == 0) b.pop_back();
      for (int i = b.size() - 1; i >= 0; i--) cout << b[i];
      cout << endl;
    }
  }
}
