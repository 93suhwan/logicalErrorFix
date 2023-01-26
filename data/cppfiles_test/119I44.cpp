#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    double sum = 0;
    long long mn = INT_MAX, mx = INT_MIN;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (mn > a[i]) mn = a[i];
      if (mx < a[i]) mx = a[i];
    }
    sum = sum / n;
    long long avg = ceil(sum);
    long long u = mx - mn;
    if (u == 0)
      cout << u << "\n";
    else {
      cout << u - avg << "\n";
    }
  }
  return 0;
}
