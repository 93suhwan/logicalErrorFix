#include <bits/stdc++.h>
using namespace std;
void init_code() {}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    b = b >> 1;
    a = a * a;
  }
  return res;
}
int32_t main() {
  init_code();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  long long f = 1;
  while (t--) {
    long long n;
    cin >> n;
    string c1, c2;
    cin >> c1;
    string res = c1;
    res.erase(1);
    string prev = c1;
    for (long long i = 0; i < n - 3; i++) {
      string cf;
      cin >> cf;
      if (prev[1] == cf[0]) {
        res += cf[0];
      } else if (prev[1] != cf[0]) {
        res += (prev[1]);
        res += cf[0];
      }
      prev = cf;
    }
    res += prev[1];
    if (res.size() != n) res += "a";
    cout << res << "\n";
  }
  return 0;
}
