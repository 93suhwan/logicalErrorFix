#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    map<int, vector<array<int, 2>>> mp;
    long long bsum = 0, asum = 0;
    long long mn = 0, mx = 0;
    for (int i = 0; i < (int)n; i++) {
      long long a, b;
      cin >> a >> b;
      long long mna = max(0LL, m - b), mxa = min(a, m);
      bsum += b;
      asum += a;
      long long remmina = a - mxa, remmmaxa = a - mna;
      mn += remmina;
      mx += remmmaxa;
    }
    long long ans = LLONG_MAX;
    for (int a = mn; a < (int)mx + 1; a++) {
      long long b = n * m - a;
      ans = min(ans, llabs(2 * a - (bsum - n * m + asum)));
    }
    cout << ans << '\n';
  }
}
