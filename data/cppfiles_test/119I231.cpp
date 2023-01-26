#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long int c1 = 0, c2 = 0;
    for (long long int i = 0; i < n; ++i) {
      if (a[i] == a[0]) {
        c1++;
      }
      if (a[i] == a[n - 1]) {
        c2++;
      }
    }
    long long int gap = (c2 * a[n - 1]) - (c1 * a[0]);
    if (gap & 1) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << "\n";
  }
  return 0;
}
