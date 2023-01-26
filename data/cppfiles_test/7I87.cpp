#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> difs(n - 1);
  for (int i = 0; i < n - 1; i++) difs[i] = abs(a[i + 1] - a[i]);
  vector<long long> cj(n - 1);
  vector<long long> fj(n - 1);
  cj[n - 2] = 1;
  fj[n - 2] = difs[n - 2];
  long long res = 1;
  for (int i = n - 3; i >= 0; i--) {
    if (gcd(difs[i], fj[i + 1]) > 1) {
      cj[i] = cj[i + 1] + 1;
      fj[i] = gcd(difs[i], fj[i + 1]);
    } else {
      cj[i] = 1;
      fj[i] = difs[i];
      for (int k = 1; k < cj[i + 1]; k++) {
        if (gcd(fj[i], difs[i + k]) > 1) {
          cj[i]++;
          fj[i] = gcd(fj[i], difs[i + k]);
        } else
          break;
      }
    }
    res = max(res, cj[i]);
  }
  cout << res + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tst;
  cin >> tst;
  while (tst--) solve();
  return 0;
}
