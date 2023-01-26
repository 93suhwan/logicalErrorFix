#include <bits/stdc++.h>
using namespace ::std;
int main(int argc, const char* argv[]) {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long d = 1;
    long long ans = 0;
    while (d < k && d < n) {
      d = d << 1;
      ans++;
    }
    if (d >= n) {
      cout << ans << endl;
    } else {
      long double fi = double(n - d) / k;
      ans += (ceil(fi));
      cout << ans << endl;
    }
  }
  return 0;
}
