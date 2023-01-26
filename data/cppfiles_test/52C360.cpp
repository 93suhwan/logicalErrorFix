#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % 1000000007;
      ;
      b--;
    } else {
      a = (a * a) % 1000000007;
      ;
      b /= 2;
    }
  }
  return res;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<long long> v;
    while (k) {
      v.push_back(k % 2);
      k /= 2;
    }
    for (int i = 0; i < v.size(); i++) {
      if (v[i]) {
        ans = (ans + power(n, i)) % 1000000007;
        ;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
