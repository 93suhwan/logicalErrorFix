#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e12;
const long long int MAX = 1e5 + 5;
;
const long long int MAXK = 105;
const long long int mod = 1e9 + 7;
const double esp = 1e-6;
long long int gcd(long long int a, long long int b) {
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int g = 0;
  for (long long int j = 0; j < 31; j++) {
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      if ((1 << j) & v[i]) {
        cnt++;
      }
    }
    g = gcd(g, cnt);
  }
  if (g == 0) {
    for (long long int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  } else {
    vector<long long int> k;
    for (long long int i = 1; i * i <= g; i++) {
      if (g % i == 0) {
        k.push_back(i);
        if (i != (g / i)) {
          k.push_back(g / i);
        }
      }
    }
    sort(k.begin(), k.end());
    for (auto u : k) {
      cout << u << " ";
    }
    cout << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
