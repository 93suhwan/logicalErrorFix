#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
long long M = 1e9 + 7;
double eps = 1e-12;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % n == 0) {
    cout << 0 << "\n";
    return;
  }
  cout << 1 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
