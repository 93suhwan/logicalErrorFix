#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    long long ans = 1e9;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) ans = min(ans, v[j] & v[i]);
    }
    cout << ans << "\n";
  }
}
