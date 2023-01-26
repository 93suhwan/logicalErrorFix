#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long mod = 1000000007;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long k = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0 || a[i] == 1) k++;
  }
  if (k >= 1) cout << pow(2, k - 1) << endl;
  if (k == 0) cout << 0 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
