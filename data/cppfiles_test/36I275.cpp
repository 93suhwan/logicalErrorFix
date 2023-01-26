#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1000000007;
long double pi = 3.14159265;
double eps = 1e-12;
void solve() {
  int n;
  cin >> n;
  if (n <= 26) {
    int count = 0;
    while (n--) {
      cout << (char)('a' + count++);
    }
    cout << "\n";
    return;
  } else {
    if (n & 1) {
      for (int i = 0; i < n / 2; i++) cout << 'a';
      cout << "bc";
      for (int i = 0; i < n / 2 - 1; i++) cout << 'a';
    } else {
      for (int i = 0; i < n / 2; i++) cout << 'a';
      cout << 'b';
      for (int i = 0; i < n / 2 - 1; i++) cout << 'a';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
