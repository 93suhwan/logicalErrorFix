#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
void solve() {
  long long n;
  cin >> n;
  long long res = 1;
  while (n != 0) {
    if (!(res % 3 == 0 || res % 10 == 3)) n--;
    res++;
  }
  cout << res - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
