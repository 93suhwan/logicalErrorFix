#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long int N = 10e5 + 10;
const long long int M = 32767;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, f = 1, count = 1;
    cin >> n >> k;
    long long int a[n], b[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    for (long long int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        count++;
      }
    }
    if (k >= count) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
