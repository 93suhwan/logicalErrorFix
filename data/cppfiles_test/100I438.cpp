#include <bits/stdc++.h>
using namespace std;
const long mod = 1e9 + 7;
long long binpow(long long a, long long b) {
  long m = mod;
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const int mx = 1e6;
vector<long> fact(mx);
void process() {
  fact[0] = fact[1] = 1;
  for (long i = 2; i <= mx; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  process();
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n;
    map<int, int> m;
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (m[x] == 0) {
        mx = max(x, mx);
      }
      m[x]++;
    }
    if (m[mx] > 1) {
      cout << fact[n] << endl;
      continue;
    } else if (m[mx - 1] == 0) {
      cout << 0 << endl;
      continue;
    }
    long long pp = fact[n] / (m[mx - 1] + 1);
    cout << fact[n] - pp << endl;
  }
  return 0;
}
