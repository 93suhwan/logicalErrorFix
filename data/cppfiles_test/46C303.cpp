#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;
long long test, a[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    long long mx = 0;
    long long pr = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] >= mx) {
        mx = a[i];
        pr = i;
      }
    }
    mx = 0;
    long long ans = 0;
    for (long long i = n; i > pr; i--)
      if (a[i] > mx) {
        ans++;
        mx = a[i];
      }
    cout << ans << endl;
  }
  return 0;
}
