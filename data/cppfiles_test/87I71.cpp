#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long k = 0;
    long long m = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] >= i + 1) {
        k += a[i] - (i + 1);
      }
    }
    cout << k << endl;
  }
  return 0;
}
