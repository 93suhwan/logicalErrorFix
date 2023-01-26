#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int CONSTANT = 2e5 + 1;
long long int mult(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int binpow(long long int a, long long int b) {
  a = a % mod;
  long long int res = 1;
  while (b) {
    if (b & 1) res = mult(res, a);
    b >>= 1;
    a = mult(a, a);
  }
  return res;
}
bool compare(pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int d = abs(a - b);
    int d2 = d << 1;
    if (a <= d2 && b <= d2 && c <= d2) {
      if (c + d <= d2) {
        cout << c + d << endl;
      } else if (c - d > 0) {
        cout << c - d << endl;
      } else
        cout << -1 << endl;
    } else
      cout << -1 << endl;
  }
}
