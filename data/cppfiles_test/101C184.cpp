#include <bits/stdc++.h>
using namespace std;
long long fp(long long x, long long y, long long m = 998244353) {
  long long ANS = 1;
  while (y) {
    if (y & 1) ANS = (ANS * x) % 998244353;
    x = (x * x) % 998244353;
    y >>= 1;
  }
  return ANS;
}
long long inv(long long x, long long m = 998244353) { return fp(x, m - 2); }
long long testcases, arr[200001], n;
string s;
int32_t main() {
  iostream::sync_with_stdio(0), cin.tie(0);
  cin >> testcases;
  while (testcases--) {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    cin >> s;
    multiset<long long> L, S;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'R')
        L.insert(arr[i]);
      else
        S.insert(arr[i]);
    }
    for (long long i = 1; i <= n; i++) {
      auto itr = S.lower_bound(i);
      if (itr == S.end()) {
        auto itr2 = L.upper_bound(i);
        if (itr2 == L.begin()) {
          cout << "NO" << '\n';
          goto a;
        }
        itr2--;
        L.erase(itr2);
      } else
        S.erase(itr);
    }
    cout << "YES" << '\n';
  a:;
  }
}
