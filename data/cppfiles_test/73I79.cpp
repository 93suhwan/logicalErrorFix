#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t-- != 0) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if ((i + 1) % 2 == 0) {
        if (a[i] > a[i + 1]) {
          cnt++;
          swap(a[i], a[i + 1]);
        }
      } else {
        if (a[i] > a[i + 1]) {
          cnt++;
          swap(a[i], a[i + 1]);
        }
      }
    }
    if (cnt != 0) {
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
