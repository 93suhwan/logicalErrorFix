#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n], cnt = 1;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (i && a[i] < a[i - 1]) {
        cnt++;
      }
    }
    if (cnt <= k) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
