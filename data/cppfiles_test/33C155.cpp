#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int i, k = 0, mx = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 1; i < n; i++) mx = max(mx, a[i - 1] * a[i]);
    cout << mx << endl;
  }
  return 0;
}
