#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    for (long long i = 0; i < n; ++i) cin >> b[i];
    map<long long, long long> ca, cb;
    for (long long i = 0; i < n; ++i) {
      ca[a[i]]++;
      cb[b[i]]++;
    }
    long long nap = 0;
    for (long long i = 0; i < n; ++i) {
      long long ta = ca[a[i]] - 1, tb = cb[b[i]] - 1;
      nap += ta * tb;
    }
    long long ans = n * (n - 1) * (n - 2);
    ans /= 6;
    ans -= nap;
    cout << ans << endl;
  }
}
