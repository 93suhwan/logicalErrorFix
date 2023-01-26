#include <bits/stdc++.h>
using namespace std;
const long long n = 1e9;
vector<long long> p;
map<long long, long long> q;
set<long long> r;
long long binary(long long a) {
  long long j = 1, count = 0;
  for (long long i = 1; i <= a; i++) {
    long long p = 6, res = 1, j = i;
    while (p > 0) {
      if (p & 1) res = res * j;
      j = j * j;
      p >>= 1;
    }
    if (res <= a) {
      count++;
    } else {
      return count;
      break;
    }
  }
}
void solve() {
  long long a;
  cin >> a;
  long long b = sqrt(a);
  long long c = cbrt(a);
  long long x = binary(a);
  cout << b + c - x << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
