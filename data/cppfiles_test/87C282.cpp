#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a[100], n;
  cin >> t;
  for (long long h = 0; h < t; h++) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long k = 0;
    for (long long i = 1; i <= n; i++) {
      if (a[i - 1] > i + k) k += a[i - 1] - (i + k);
    }
    cout << k << endl;
  }
}
