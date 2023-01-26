#include <bits/stdc++.h>
using namespace std;
long long int msbPos(long long n) {
  long long int msb_p = -1;
  while (n) {
    n = n >> 1;
    msb_p++;
  }
  return msb_p;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long a = msbPos(l);
  long long b = msbPos(r);
  if (a == b) {
    cout << 0 << endl;
    return;
  } else {
    vector<long long> v(b - a + 1);
    v[0] = (binpow(2, a)) - (l % (binpow(2, a)));
    v[b - a] = (r % (binpow(2, b))) + 1;
    for (long long i = 1; i < b - a; i++) {
      v[i] = binpow(2, a + i);
    }
    long long s = 0;
    for (long long i = 0; i < b - a + 1; i++) {
      s += v[i];
    }
    sort(v.rbegin(), v.rend());
    if (b - a + 1 > 2 && a == 0) {
      s--;
    }
    cout << (s - v[0]) << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
}
