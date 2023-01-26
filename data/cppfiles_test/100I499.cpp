#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int mx = 5e6;
vector<long long> fact(mx + 1);
void process() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i <= mx; i++) {
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
    map<int, long long> m;
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
