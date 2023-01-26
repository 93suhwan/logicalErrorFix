#include <bits/stdc++.h>
const double PI = 3.14159265359;
const int mod = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    bitset<100> k;
    cin >> n >> m;
    k = m;
    vector<long long> pw;
    pw.push_back(1);
    while (pw.size() < 100) pw.push_back((pw.back() * n) % mod);
    long long ans = 0;
    for (int(i) = 0; (i) < 100; (i)++) {
      if (k[i]) {
        ans += pw[i];
        ans %= mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
