#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {}
long long countSquares(long long a, long long b) {
  return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}
long long countCubes(long long a, long long b) {
  long long acrt = cbrt(a);
  long long bcrt = cbrt(b);
  long long count = 0;
  for (long long i = acrt; i <= bcrt; i++)
    if (i * i * i >= a && i * i * i <= b) count++;
  return count;
}
long long SquareCube(long long int N) {
  long long cnt = 0, i = 1;
  while (long long(pow(i, 6)) <= N) {
    ++cnt;
    ++i;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    long long n;
    cin >> n;
    long long res = countCubes(1, n) + countSquares(1, n) - SquareCube(n);
    cout << res << endl;
  }
  return 0;
}
