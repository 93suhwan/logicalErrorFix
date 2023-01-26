#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], mx, cnt = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    mx = a[n - 1];
    for (long long i = n - 1; i >= 0; i--) {
      if (a[i] > mx) {
        mx = a[i];
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
