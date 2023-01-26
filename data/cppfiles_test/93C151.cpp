#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long curr = 1, ans = 0;
    while (curr < n && curr < k) {
      curr *= 2;
      ans++;
    }
    if (curr < n) ans += (n - curr + k - 1) / k;
    cout << ans << endl;
  }
}
