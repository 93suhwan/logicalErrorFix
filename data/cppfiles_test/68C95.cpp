#include <bits/stdc++.h>
using namespace std;
long long int t, k, r, c;
void solve() {
  cin >> k;
  long long int init = sqrt(k);
  while (init * init < k) init++;
  if (init * init == k) {
    r = init;
    c = 1;
  } else {
    long long int inf = (init - 1) * (init - 1);
    long long int sup = (init * init);
    long long int m = (inf + sup + 1) / 2;
    if (k < m) {
      r = sqrt(sup) - (m - k);
      c = sqrt(sup);
    } else {
      c = sup - k + 1;
      r = sqrt(sup);
    }
  }
  cout << r << " " << c << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
  return 0;
}
