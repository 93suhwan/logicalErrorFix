#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int mxm = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long int ans = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != i + 1) {
        if (a[i] > 2 * (i + 1)) {
          ans++;
        } else {
          ans = -1;
          break;
        }
      }
    }
    cout << (ans) << endl;
  }
  return 0;
}
