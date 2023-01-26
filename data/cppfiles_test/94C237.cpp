#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0;
    cin >> n >> k;
    k++;
    long long p, c, d;
    cin >> p;
    for (int i = 1; i < n; i++) {
      cin >> c;
      d = min((long long)pow(10, c - p) - 1, k);
      ans += (long long)pow(10, p) * d;
      k -= d;
      p = c;
    }
    ans += (long long)pow(10, p) * k;
    cout << ans << endl;
  }
  return 0;
}
