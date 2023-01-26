#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b;
    b.reserve(n * 2);
    b.push_back(0);
    long long mel = 0, indm = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] >= mel) {
        mel = a[i];
        indm = i;
      }
    }
    long long ans = 0;
    if (indm == n - 1) {
      ans = 0;
    } else {
      for (int i = n - 1; i > indm; i--) {
        if (a[i] > b[b.size() - 1]) {
          b.push_back(a[i]);
        }
      }
      ans = b.size() - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
