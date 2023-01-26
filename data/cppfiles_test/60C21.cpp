#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, x, mx = INT_MIN;
    cin >> n;
    long long a[n], i, c;
    map<long long, long long> mp;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    x = a[0];
    for (i = 1; i < n; i++) {
      x &= a[i];
    }
    cout << x << "\n";
  }
}
