#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << "1\n";
    return;
  }
  vector<long long> difs(n - 1);
  for (int i = 0; i < n - 1; i++) difs[i] = abs(a[i + 1] - a[i]);
  vector<long long> cj(n);
  vector<long long> fj(n);
  cj[n - 1] = 0;
  fj[n - 1] = 1;
  long long res = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (gcd(difs[i], fj[i + 1]) > 1) {
      cj[i] = cj[i + 1] + 1;
      fj[i] = gcd(difs[i], fj[i + 1]);
    } else {
      cj[i] = int(difs[i] > 1ll);
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
