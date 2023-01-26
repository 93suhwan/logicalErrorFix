#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
      sum += v[i];
    }
    if (n == 2) {
      cout << 0 << "\n";
    } else if (sum % n == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
