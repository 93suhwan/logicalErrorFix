#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod = 1e9 + 7;
const long long base = 31;
void fre() {}
clock_t start = clock();
double timecomplexity;
long long n, a[(long long)(1e6 + 9)], tmp, ct;
void solve() {
  cin >> n;
  tmp = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    tmp += a[i];
  }
  tmp *= 2;
  if (tmp % n) {
    cout << 0;
    return;
  }
  tmp /= n;
  ct = 0;
  map<long long, long long> m;
  for (long long i = 1; i <= n; i++) {
    ct += m[tmp - a[i]];
    m[a[i]]++;
  }
  cout << ct;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
}
