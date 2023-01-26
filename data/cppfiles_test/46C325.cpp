#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long x = arr[n - 1];
    long long cnt = 0;
    for (long long i = n - 2; i >= 0; i--) {
      if (x < arr[i]) {
        x = arr[i];
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
