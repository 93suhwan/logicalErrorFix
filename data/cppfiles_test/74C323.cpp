#include <bits/stdc++.h>
using namespace std;
int mod1 = 998244353;
int mod2 = 1000000007;
int MOD = mod2;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int a, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    set<int> k;
    long long int x = min(a, b), n = a + b;
    for (int i = 0; i < x + 1; i++) {
      k.insert(i + n / 2 - x + i);
      k.insert(i + (n + 1) / 2 - x + i);
    }
    cout << k.size() << "\n";
    for (int u : k) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
