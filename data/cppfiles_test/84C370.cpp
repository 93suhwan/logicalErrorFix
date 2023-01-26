#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int mod = 1000000007;
const double PI = 3.141592653589793238;
const long long int INF = 1e18;
const long long int p = 998244353;
int main() {
  long long int t = 1;
  cin >> t;
  for (int test = 0; test < t; test++) {
    double n, s;
    cin >> n >> s;
    bool chk = 0;
    if (((long long int)n) % 2 == 0) {
      chk = 1;
    }
    long long int x;
    if (chk) {
      x = (n / 2) + 1;
    } else {
      x = ceil(n / 2);
    }
    cout << (long long int)floor(s / x) << "\n";
  }
}
