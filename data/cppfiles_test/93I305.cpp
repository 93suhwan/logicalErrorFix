#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int s = 0;
    long long int x = 1;
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    bool temp = 0;
    while (x <= n) {
      if (x <= k) {
        s++;
        x = x * 2;
      } else
        break;
    }
    if (x > n) x = n;
    long long int rem = n - x;
    s += rem / k;
    if (rem % k > 0) s++;
    cout << s << '\n';
  }
  return 0;
}
