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
    long long ans = v[0];
    for (long long i = 0; i < n; i++) {
      ans &= v[i];
    }
    cout << ans << "\n";
  }
}
