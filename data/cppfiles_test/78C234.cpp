#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
const long long MOD = 1e9 + 7;
const long long M = 1e18;
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int l, r;
    cin >> l >> r;
    int k = (r + 1) / 2;
    if (k >= l)
      cout << k - 1;
    else
      cout << r % l;
    cout << endl;
  }
  return 0;
}
