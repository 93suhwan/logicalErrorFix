#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
long long pow_mod(long long a, long long e) {
  long long res = 1;
  for (; e; a = a * a % mod, e >>= 1)
    if (e & 1) res = res * a % mod;
  return res;
}
long long n, m, k, r, c;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k >> r >> c;
  cout << pow_mod(k, n * m - r * c) << endl;
  return 0;
}
