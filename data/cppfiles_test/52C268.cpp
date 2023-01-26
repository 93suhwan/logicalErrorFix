#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long f() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long base = 1;
  while (k > 0) {
    ans = (ans + (k & 1) * base) % mod;
    k = k / 2;
    base = (base * n) % mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cout << f() << '\n';
  }
  return 0;
}
