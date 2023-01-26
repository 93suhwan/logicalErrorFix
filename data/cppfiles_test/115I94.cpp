#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    long long x = ceil(h / (n * 1.0));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int f = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] - a[i - 1] < x) {
        f = 0;
        break;
      }
    }
    if (f)
      cout << x << "\n";
    else {
      int i = 0;
      long long sum = 0;
      while (a[i + 1] - a[i] < x) {
        sum += a[i + 1] - a[i];
        i++;
      }
      x = ceil((h - sum) / 2.0);
      cout << x << "\n";
    }
  }
  return 0;
}
