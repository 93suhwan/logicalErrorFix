#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 << " " << n << "\n";
  } else {
    cout << n / 2 << " " << n - 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
