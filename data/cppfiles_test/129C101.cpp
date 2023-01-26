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
    set<long long int> x;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      x.insert(i + 1);
    }
    sort(a, a + n);
    for (i = 0; i < n; i++) {
      if (x.count(a[i])) {
        x.erase(a[i]);
        a[i] = 0;
      }
    }
    long long int ans = 0;
    sort(a, a + n);
    for (i = 0; i < n; i++) {
      if (a[i] > 0) {
        if (2 * (*x.begin()) < a[i]) {
          x.erase(x.begin());
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
