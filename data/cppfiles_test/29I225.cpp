#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long mod = 1000000007;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long k0 = 0;
  long long k1 = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) k0++;
    if (a[i] == 1) k1++;
  }
  if (k0 == 0) cout << k1 << endl;
  if (k0 > 0) cout << k1 * pow(2, k0) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
