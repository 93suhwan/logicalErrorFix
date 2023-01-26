#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
void go() {
  long long n;
  cin >> n;
  vector<long long> h(n);
  for (long long &x : h) cin >> x;
  long long k = 0;
  for (long long j = 1e9; j > 0; j /= 2) {
    long long x = k + j;
    bool valid = true;
    vector<long long> hc = h;
    for (int i = n - 1; i >= 2; i--) {
      if (hc[i] < x) valid = false;
      long long d = min((hc[i] - x) / 3, h[i] / 3);
      hc[i - 1] += d;
      hc[i - 2] += d * 2;
    }
    if (hc[0] < x || hc[1] < x) valid = false;
    if (valid) {
      k = x;
      j *= 2;
    }
  }
  cout << k << endl;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) go();
}
